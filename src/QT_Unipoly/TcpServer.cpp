#include "TcpServer.hpp"

int host=0, start=0, n_players=1;


TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    connect(&_server, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);
    connect(this, &TcpServer::newMessage, this, &TcpServer::onNewMessage);
    connect(this, &TcpServer::canStart, this, &TcpServer::onCanStart);
    connect(this, &TcpServer::deletePlayer3, this, &TcpServer::onDeletePlayer3);
    connect(this, &TcpServer::deletePlayer4, this, &TcpServer::onDeletePlayer4);
}

void TcpServer::launchServer(int n, QString name)
{
    if(_server.listen(QHostAddress::Any, 12345)) {
        qInfo() << "Listening ...";
        _game->set_n_players(n);
        _game->saveinfo("0", name);
        maxplayers=n;
        host=1;
    } else {
        qWarning() << "Could not start server.";
    }
    if(maxplayers==2){
        emit deletePlayer3();
        emit deletePlayer4();
        emit _game->deleteGPlayer3();
        emit _game->deleteGPlayer4();
    }
    else if(maxplayers==3){
        emit deletePlayer4();
        emit _game->deleteGPlayer4();
    }
    //print ip address
    // QList<QHostAddress> list = QNetworkInterface::allAddresses();
    // qInfo() << "IP: " << list[4].toString();
    // qInfo() << "Port: 12345";
}
void TcpServer::sendMessage(const QString &message2send)
{
    qInfo()<<">>Sent message: "<<message2send;
    emit newMessage("Server: " + message2send.toUtf8());
}

void TcpServer::onNewConnection()
{
    const auto client = _server.nextPendingConnection();
    if(client == nullptr) {
        return;
    }

    qInfo() << "New client connected.";

    _clients.insert(this->getClientKey(client), client);

    connect(client, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
    connect(client, &QTcpSocket::disconnected, this, &TcpServer::onClientDisconnected);
}

void TcpServer::onReadyRead()
{
    const auto client = qobject_cast<QTcpSocket*>(sender());
    int code=0;
    if(client == nullptr) {
        return;
    }

    QString id = this->getClientKey(client).toUtf8();
    QString receivedmessage = client->readAll();

    if(n_players!=_game->numberofplayers){
        qInfo() << receivedmessage;
        _game->saveinfo(id, receivedmessage);
        n_players++;

    }
    else{
        this->actions(_game->code_2_action(receivedmessage.toStdString()));
    }


    if(maxplayers==_game->players.size() && start==0){
           emit canStart();
           start=1;
    }
    else
        qInfo() << "Waiting for players ...";

    //emit newMessage(receivedmessage.toUtf8());
}

void TcpServer::onClientDisconnected()
{
    const auto client = qobject_cast<QTcpSocket*>(sender());

    if(client == nullptr) {
        return;
        n_players--;
    }

    _game->deleteinfo(this->getClientKey(client));
    _clients.remove(this->getClientKey(client));
}

void TcpServer::onNewMessage(const QByteArray &ba)
{
    for(const auto &client : qAsConst(_clients)) {
        client->write(ba);
        client->flush();
    }
}

void TcpServer::onCanStart()
{
     qInfo() << "Game can start";
}


void TcpServer::onDeletePlayer3()
{
    qInfo() << "Player 3 deleted";
}
void TcpServer::onDeletePlayer4()
{
    qInfo() << "Player 4 deleted";
}

QString TcpServer::getClientKey(const QTcpSocket *client) const
{
    return client->peerAddress().toString().append(":").append(QString::number(client->peerPort()));
}

void TcpServer::closeserver()
{
    if(host==1){
        _server.close();
        _game->deleteinfo("0");
        qInfo()<<"Server closed";
        start=0;
        n_players=0;
        host=0;
    }
}

void TcpServer::set_game(GameLogic *game){
    this->_game = game;
}

void TcpServer::sendStart(){
    QString name1, name2, name3, name4;
    name1=QString::fromStdString(_game->players[0].name);
    name2=QString::fromStdString(_game->players[1].name);
    if(_game->numberofplayers==3){
        name3=QString::fromStdString(_game->players[2].name);
        name4="NULL";
    }
    else if(_game->numberofplayers==4){
        name3=QString::fromStdString(_game->players[2].name);
        name4=QString::fromStdString(_game->players[3].name);
    }
    else{
        name3="NULL";
        name4="NULL";
    }
    const auto message = "10_0_"+name1+"_1_"+name2+"_2_"+name3+"_3_"+name4;
    qInfo()<<message;
    sendMessage(message);
}

void TcpServer::sendNextPlayer(){

    if(_game->nextPlayer()==true){
        std::string name=_game->get_game().get_current_player()->get_name();
        QString injail;
        if(_game->get_game().get_current_player()->get_if_in_jail()){
            _game->get_game().get_current_player()->add_turn_in_jail();
            if(_game->get_game().get_current_player()->get_turns_in_jail()==3){
                _game->get_game().get_current_player()->change_jail_status();
                _game->get_game().get_current_player()->reset_turns_in_jail();
                injail="0";
            }
            else
                injail="1";
        }
        else{
            injail="0";
        }

        QString message="06_"+QString::fromStdString(name)+"_"+injail;
        qInfo() << message;
        sendMessage(message);
    }
    else{      
        std::string name=_game->get_game().get_current_player()->get_name();
        QString message="06_"+QString::fromStdString(name);
        qInfo() << message;
        sendMessage(message);
    }
    updateplayers_money();
    updateplayers_position();
}

void TcpServer::updateplayers_money(){
    QString message="03";
    for(int i=0; i<_game->players.size(); i++){
        message+="_"+QString::fromStdString(_game->players[i].name)+"_"+QString::number(_game->get_game().get_player(i)->check_balance());
    }
    qInfo() << message;
    sendMessage(message);
}

void TcpServer::updateplayers_position(){
    QString message="07";
    for(int i=0; i<_game->players.size(); i++){
        message+="_"+QString::fromStdString(_game->players[i].name)+"_"+QString::number(_game->get_game().get_player(i)->get_position());
    }
    qInfo() << message;
    sendMessage(message);
}


void TcpServer::actions(int code){
    qInfo()<< "Code:" << code;
    if(code==22){
        int pos=_game->get_game().dice.get_total();
        int current_pos=_game->get_game().get_current_player()->get_position();
        std::cout<<"check if can buy position: "<< pos << "Bool state:"<<_game->get_game().board.get_property(pos)->check_if_can_buy() <<std::endl;
        if(_game->get_game().board.get_property(current_pos)->check_if_can_buy()){
            QString message= "05_"+ QString::number(pos)+"_"+QString::fromStdString(_game->get_game().get_current_player()->get_name())+"_1";
            sendMessage(message);
        }
        else{
            QString message= "05_"+ QString::number(pos)+"_"+QString::fromStdString(_game->get_game().get_current_player()->get_name())+"_0";
            sendMessage(message);
        }
    }
    if(code==23){
        int pos=_game->get_game().get_current_player()->get_position();
        std::string name=_game->get_game().get_current_player()->get_name();
        sendChangePropOwner(pos, name);
        this->sendNextPlayer();
    }
    if(code==26 || code==27 || code==28){
        //updateplayers_money();
        if(code==26){
            QString message="08_"+QString::fromStdString(_game->get_game().get_current_player()->get_name())+"_L_"+QString::number(_game->luck_chance_index);
            sendMessage(message);
        }

        else if(code==27){
            QString message="08_"+QString::fromStdString(_game->get_game().get_current_player()->get_name())+"_C_"+QString::number(_game->luck_chance_index);
            sendMessage(message);
        }

        updateplayers_money();
        this->sendNextPlayer();
    }
}

void TcpServer::sendChangePropOwner(int pos, std::string name){
    QString message;
    if(pos==0){
        message="01_"+QString::number(_game->get_game().get_current_player()->get_position())+"_"+QString::fromStdString(_game->get_game().get_current_player()->get_name());
    }
    else
        message="01_"+QString::number(pos)+"_"+QString::fromStdString(name);
    sendMessage(message);
}
void TcpServer::changePropOwner(){
    sendChangePropOwner(0, "0");
}
