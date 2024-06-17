#include "gameinit_client.h"
#include <QDebug>


GameInit_Client::GameInit_Client(QObject *parent): QObject{parent}
{
    connect(this, &GameInit_Client::init_Game, this, &GameInit_Client::onInit_Game);
    connect(this, &GameInit_Client::myTurn, this, &GameInit_Client::onMyTurn);
    connect(this, &GameInit_Client::nextPlayerDisable, this, &GameInit_Client::onNextPlayerDisable);
    connect(this, &GameInit_Client::wantToBuy, this, &GameInit_Client::onWantToBuy);
    connect(this, &GameInit_Client::close, this, &GameInit_Client::onClose);
}

void GameInit_Client::set_myname(std::string name){
    my_name=name;
}

std::string GameInit_Client::get_myname(){
    return my_name;
}


void GameInit_Client::create_game(){
    qInfo() << "Entered create_game";
    //Create players

    game.print_players();

    //create board
    game.board.create_board();
    game.board.print_board();

    if(get_number_of_players()==2){
        emit deleteGPlayer3();
        emit deleteGPlayer4();
    }
    if(get_number_of_players()==3){
        emit deleteGPlayer4();
    }
    emit updatePlayerName();


}

int GameInit_Client::code_2_action(std::string message){
    qInfo()<<"Entered code_2_action";
    std::string code = message.substr(0,message.find("_"));
    message.erase(0, message.find("_")+1);

    if(code=="10"){
        std::string id;
        std::string name;
        while( ((message.find("_")) != std::string::npos )){
            id=parse_info(&message);
            name=parse_info(&message);
            if(name!="NULL"){
                game.create_player(name, id, 1);
            }
        }
        emit init_Game();
        create_game();
    }
    if(code=="02"){
        parse_info(&message);
    }
    if(code=="06")
    {
        std::string name=parse_info(&message);
        if(game.get_current_player()->get_name()==name)
            qInfo()<<"All checks out";
        else
            game.next_player();

        if(game.get_current_player()->get_name()==my_name){
            if(parse_info(&message)=="1"){
                qInfo()<< "entrei aqui aiyga";

                game.get_current_player()->add_turn_in_jail();
                qInfo()<< "Passei";
                emit inJail();
            }
            else
                emit myTurn();
        }
        else
            emit nextPlayerDisable();
    }

    if(code=="05"){
        std::string position=parse_info(&message);
        std::string name=parse_info(&message);
        std::string buy=parse_info(&message);


        std::cout<<">>05\nPositions to move: "<< position << " Name: "<< name << " Buy: "<<buy<<std::endl;
        std::cout<<"Current player:"<<game.get_current_player()->get_name()<<std::endl;

        game.get_current_player()->set_position(stoi(position));
        emit updatePlayerPosition();
        qInfo()<< position<<" " << name<<" " << buy;
        if(my_name==name && buy=="1"){
            emit wantToBuy();
        }
        else
        {

            emit nextPlayerDisable();
            if(my_name==name){
                if(game.board.get_property(game.get_current_player()->get_position())->get_property_type()==CHANCE){
                    return 7;
                }
                if(game.board.get_property(game.get_current_player()->get_position())->get_property_type()==COMMUNITY_CHEST){
                    return 8;
                }
                return 5;
            }
        }

    }

    if(code=="03"){
        qInfo()<<"Entrei no 03";
        std::string name;
        std::string money;
        name=parse_info(&message);
        money=parse_info(&message);
        game.get_player_by_name(name)->set_money(stoi(money));
        while ( ((message.find("_")) != std::string::npos )){
            name=parse_info(&message);
            money=parse_info(&message);
            game.get_player_by_name(name)->set_money(stoi(money));
        }
        emit updatePlayerCredits();
    }

    if(code=="01"){
        std::string position=parse_info(&message);
        std::string name=parse_info(&message);
        game.board.get_property(stoi(position))->change_owner(game.get_player_by_name(name));

        QString prop_name = QString::fromStdString(game.board.get_property(stoi(position))->get_property_name());
        QString color = QString::fromStdString(game.board.get_property(stoi(position))->get_color());
        QString rent = QString::number(game.board.get_property(stoi(position))->get_rent(10));
        QString owner = QString::fromStdString(game.board.get_property(stoi(position))->get_property_owner()->get_name());

        emit updateProperty(prop_name,color,rent,owner);
    }

    if(code=="07")
    {
        qInfo()<<"Entrei no 07";
        std::string name;
        std::string position;
        name=parse_info(&message);
        position=parse_info(&message);
        game.get_player_by_name(name)->set_position(stoi(position));
        while ( ((message.find("_")) != std::string::npos )){
            name=parse_info(&message);
            position=parse_info(&message);
            game.get_player_by_name(name)->set_position(stoi(position));
        }
        emit updatePlayerPosition();
    }

    if(code=="08"){
        qInfo()<<"Entrei no 08";
        qInfo()<< message;
        std::string name=parse_info(&message);
        std::string message_type=parse_info(&message);
        std::string index=parse_info(&message);
        if(name==my_name){
            if(message_type=="L")
                emit chanceCommunityCard(QString::fromStdString(game.board.chance_cards[stoi(index)]->get_consequence()));
            else
                emit chanceCommunityCard(QString::fromStdString(game.board.community_chest_cards[stoi(index)]->get_consequence()));
        }
    }
    return 1;
}

std::string GameInit_Client::parse_info(std::string *message){
    qInfo()<<"Entered parse_info";

    std::string delimiter = "_";
    std::string code = message->substr(0, message->find(delimiter));
    message->erase(0, message->find(delimiter)+delimiter.length());

    return code;
}

QString GameInit_Client::getProperty(){
    return QString::fromStdString(game.board.get_property(game.get_current_player()->get_position())->get_property_name());
}
QString GameInit_Client::getprice(){
    return QString::number(game.board.get_property(game.get_current_player()->get_position())->get_price());
}
logic::Game GameInit_Client::get_game(){
    return game;
}
int GameInit_Client::get_number_of_players(){
    return game.number_players();
}
QString GameInit_Client::getPlayerName(int id){
    return QString::fromStdString((game.get_player(id)->get_name()));
}
void GameInit_Client::onInit_Game()
{
    qInfo() << "Game started";
}
void GameInit_Client::onMyTurn()
{
    qInfo() << "My turn";
}
void GameInit_Client::onNextPlayerDisable()
{
    qInfo() << "Next player";
}
void GameInit_Client::onWantToBuy()
{
    qInfo() << "Want to buy?";
}

void GameInit_Client::onClose(){
    qInfo() << "Closed";
}
QString GameInit_Client::getMyName_qstring(){
    return QString::fromStdString(my_name);
}

int GameInit_Client::getPlayerPosition(int player_number){
    return game.get_player(player_number)->get_position();
}

void GameInit_Client::inhere(){
    qInfo() << "Entered in_here";
}

QString GameInit_Client::getPlayerCredit(int player_number){
    return QString::number(game.get_player(player_number)->check_balance());
}


int GameInit_Client::getRent(QString property_name){
    qInfo()<<"Entered getRent";
    if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==FACULTY)
        return game.board.get_property_by_name(property_name.toStdString())->get_rent(game.dice.get_total());
    else if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==STATION)
        return game.board.get_property_by_name(property_name.toStdString())->get_rent(game.dice.get_total());
    else if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==UTILITY)
        return 0;
    return 0;
}

int GameInit_Client::getHouses(QString property_name){
    qInfo()<<"Entered getHouses"<< property_name;

    if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==FACULTY)
        return game.board.get_property_by_name(property_name.toStdString())->get_facul()->get_level();
    else
        return 0;
}

bool GameInit_Client::tryDouble(){
    game.dice.roll();
    return game.dice.check_double();
}


int GameInit_Client::get_current_balance(){
    return game.get_current_player()->check_balance();
}
