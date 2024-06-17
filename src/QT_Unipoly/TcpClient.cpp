#include "TcpClient.hpp"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    connect(&_socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
    connect(&_socket, &QTcpSocket::errorOccurred, this, &TcpClient::onErrorOccurred);
    connect(&_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
    connect(&_socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
    _game = new GameInit_Client();
}

void TcpClient::connectToServer(const QString name,const QString &ip, const QString &port)
{
    _socket.connectToHost(ip, port.toUInt());
    _socket.write(name.toUtf8());
    _game->set_myname(name.toStdString());
}

void TcpClient::sendMessage(const QString &message)
{
    _socket.write(message.toUtf8());
    qInfo()<<">>Sent message: "<<message;
    _socket.flush();
}

void TcpClient::disconnect()
{
    _socket.close();

}

void TcpClient::setgame(GameInit_Client *game){
    this->_game = game;
}

void TcpClient::onConnected()
{
    qInfo() << "Connected to host.";
}

void TcpClient::onDisconnected()
{
    emit this->_game->close();
    qInfo() << "Disconnected.";
    delete this->_game;
    this->_game=NULL;
}

void TcpClient::onReadyRead()
{
    const auto message = _socket.readAll();
    qInfo() << "<<" << message;
    int code;

    //Just to clean the message received from the server
    std::string s = message.toStdString();
    std::string saux1;
    std::string delimiter = "Server: ";
    s.erase(0, s.find(delimiter)+delimiter.length());
    //check if have another "Server:"
    if(s.find(delimiter)!=std::string::npos){
        saux1=s.substr(0, s.find(delimiter));
        s.erase(0, s.find(delimiter)+delimiter.length());
        qInfo()<<"Aux1:" << saux1;
        qInfo()<<"s: " << s;
        if(s.find(delimiter)!=std::string::npos){
            std::string saux2=s.substr(0, s.find(delimiter));
            s.erase(0, s.find(delimiter)+delimiter.length());
            qInfo()<<"Aux2:" << saux2;
            int code2=_game->code_2_action(saux2);
            if(code==5 || code2==5)
                sendEndTurn();
            else if (code==7 || code2==7)
                sendChance();
            else if (code==8 || code2==8)
                sendCommunity();
        }
        qInfo() << "<<" << saux1;
        qInfo() << "<<" << s;
        code=_game->code_2_action(s);
        int code1=_game->code_2_action(saux1);
        if(code==5 || code1==5)
            sendEndTurn();
        else if (code==7 || code1==7)
            sendChance();
        else if (code==8 || code1==8)
            sendCommunity();
    }
    else{
        code=_game->code_2_action(s);
        if(code==5)
            sendEndTurn();
        else if (code==7)
            sendChance();
        else if (code==8)
            sendCommunity();
    }
    //receive the coded message and then translate it to a real action in the dummmy client game

    // if(code==6)
    //     sendEndTurn();

}

void TcpClient::onErrorOccurred(QAbstractSocket::SocketError error)
{
    qWarning() << "Error:" << error;
}

void TcpClient::sendDiceRoll(){
    QString message = "22_"+QString::fromStdString(_game->get_myname());
    sendMessage(message);
}

void TcpClient::sendBuyProperty(){
    QString message="23_"+QString::fromStdString(_game->get_myname())+"_"+QString::number(_game->get_game().get_current_player()->get_position());
    sendMessage(message);
}

void TcpClient::sendEndTurn(){
    QString message="28_"+QString::fromStdString(_game->get_myname());
    emit this->_game->nextPlayerDisable();
    sendMessage(message);
}

void TcpClient::sendChance(){
    QString message="26_"+QString::fromStdString(_game->get_myname());
    sendMessage(message);
}

void TcpClient::sendCommunity(){
    QString message="27_"+QString::fromStdString(_game->get_myname());
    sendMessage(message);
}


void TcpClient::sendPayBill(){
    QString message="29_1";
    _game->get_game().get_current_player()->change_jail_status();
    _game->get_game().get_current_player()->reset_turns_in_jail();
    sendMessage(message);
    emit this->_game->myTurn();
}


void TcpClient::senDouble(){
    if(_game->tryDouble()){
        QString message="29_2";
        _game->get_game().get_current_player()->change_jail_status();
        _game->get_game().get_current_player()->reset_turns_in_jail();
        sendMessage(message);
        emit this->_game->myTurn();

    }
    else{
        sendEndTurn();
    }
}
