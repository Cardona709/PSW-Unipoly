#include "gameinit.h"
#include <QDebug>


GameLogic::GameLogic(QObject *parent)
    : QObject{parent}
{
    connect(this, &GameLogic::startGame, this, &GameLogic::onstartGame);
    connect(this, &GameLogic::nextPlayerDisable, this, &GameLogic::onNextPlayerDisable);
    connect(this, &GameLogic::myTurn, this, &GameLogic::onMyTurn);
    connect(this, &GameLogic::deleteGPlayer3, this, &GameLogic::onDeleteGPlayer3);
    connect(this, &GameLogic::deleteGPlayer4, this, &GameLogic::onDeleteGPlayer4);
    connect(this, &GameLogic::updatePlayerCredits, this, &GameLogic::onupdatePlayerscredits);
    qDebug() <<"Creating GameInit";
}

void GameLogic::saveinfo(QString id, QString name){

    init_info player(name.toStdString(), id.toStdString());
    players.push_back(player);

    // for(int i=0; i<players.size(); i++){
    //     qInfo()<< "Player " + std::to_string(i) + " is: " + players[i].name;
    // }
    //qInfo()<< "Number of players is: " + std::to_string(players.size());
}

void GameLogic::deleteinfo(QString id){
    for(int i=0; i<players.size(); i++){
        if(players[i].id==id.toStdString()){
            qInfo()<< "Player " + players[i].name + " deleted";
            players.erase(players.begin()+i);
        }
    }
}

void GameLogic::set_n_players(int number){
    numberofplayers=number;
    qInfo()<< "Max Number of players is: " + std::to_string(number);
}

bool GameLogic::getMortgage_status(QString property_name){
    return game.board.get_property_by_name(property_name.toStdString())->get_if_mortgaged();
}


////////////////////
QString GameLogic::getPlayerCredits(int player_number){
    int credits = 0;
    if(player_number<2){
        if(game.get_player(player_number)){
            credits=game.get_player(player_number)->check_balance();
        }
        else
            return "0";
    }
    if(get_number_of_players()>2){
        credits=game.get_player(player_number)->check_balance();
    }

    return QString::number(credits);
}

int GameLogic::getPlayerPosition(int player_number){
    if(player_number<2){
        if(game.get_player(player_number)){
            return game.get_player(player_number)->get_position();
        }
        else
            return -1;
    }
    else
        return -1;
}

//Game initialization

void GameLogic::startGame(){
    qInfo()<< "Game started";
    //Create players

    for(int i=0; i<players.size(); i++){
        game.create_player(players[i].name,players[i].id, 1);
    }

    if(players.size()==3){
        emit deleteGPlayer4();
    }
    else if(players.size()==2){
        emit deleteGPlayer4();
        emit deleteGPlayer3();
    }

    game.print_players();
    //create board
    game.board.create_board();
    game.print_players();
    emit updatePlayerName();
}

void GameLogic::rollDice(){
    game.dice.roll();
    qInfo()<< "Dice rolled";
    game.dice.get_dices();
    game.move_current_player(game.dice.get_total());
    game.print_players();

    if(game.board.get_property(game.get_current_player()->get_position())->get_property_type()==GO_TO_JAIL){
        game.get_current_player()->set_position(10);
        game.get_current_player()->change_jail_status();
    }

    if(game.get_current_player()==game.get_player(0)){
        if(game.board.get_property(game.get_current_player()->get_position())->get_property_type()==CHANCE)
            getChanceCard();
        else if(game.board.get_property(game.get_current_player()->get_position())->get_property_type()==COMMUNITY_CHEST)
            getCommunityCard();
    }
    emit updatePlayerPosition();
    emit updatePlayerCredits();

}

QString GameLogic::getProperty(){
    logic::Property* landed_property;

    landed_property=game.board.get_property(game.get_current_player()->get_position());

    if(landed_property->get_property_type()==FACULTY || landed_property->get_property_type()==UTILITY || landed_property->get_property_type()==STATION)
        if(!game.board.get_property(game.get_current_player()->get_position())->check_if_can_buy()){
            game.get_current_player()->take_money(landed_property->get_rent(game.dice.get_total()));
            landed_property->get_property_owner()->give_money(landed_property->get_rent(game.dice.get_total()));
            emit updatePlayerCredits();
            return "PAYRENT";
        }
        else
            return QString::fromStdString(game.board.get_property(game.get_current_player()->get_position())->get_property_name());
    else
        return "NULL";
}

QString GameLogic::getprice(){
    return QString::number(game.board.get_property(game.get_current_player()->get_position())->get_price());
}

int GameLogic::getHouses(QString property_name){
    qInfo()<<"Entered getHouses"<< property_name;

    if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==FACULTY)
        return game.board.get_property_by_name(property_name.toStdString())->get_facul()->get_level();
    else
        return 0;
}

int GameLogic::getBuildHousePrice(QString property_name){
    if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==FACULTY)
        return game.board.get_property_by_name(property_name.toStdString())->get_facul()->get_build_house_price();
    else
        return 0;
}

void GameLogic::buyProperty(){
    int pos=0;
    pos=game.get_current_player()->get_position();
    std::cout<<"check if can buy position: "<< pos << "Bool state:"<<game.board.get_property(pos)->check_if_can_buy() <<std::endl;
    if(game.board.get_property(pos)->check_if_can_buy()){
        game.board.get_property(pos)->buy_property(game.get_current_player(), game.board.get_property(pos)->get_property_type());

        if(game.board.get_property(pos)->get_property_type()==STATION)
        {
            if(game.board.get_property(5)->get_property_owner()==game.get_current_player() && pos!=5){
                game.board.get_property(5)->get_station()->increase_level();
                game.board.get_property(pos)->get_station()->increase_level();
            }
            if(game.board.get_property(15)->get_property_owner()==game.get_current_player() && pos!=15){
                game.board.get_property(15)->get_station()->increase_level();
                game.board.get_property(pos)->get_station()->increase_level();
            }
            if(game.board.get_property(25)->get_property_owner()==game.get_current_player() && pos!=25){
                game.board.get_property(25)->get_station()->increase_level();
                game.board.get_property(pos)->get_station()->increase_level();
            }
            if(game.board.get_property(35)->get_property_owner()==game.get_current_player() && pos!=35){
                game.board.get_property(35)->get_station()->increase_level();
                game.board.get_property(pos)->get_station()->increase_level();
            }
        }

        game.print_players();

        QString property=QString::fromStdString(game.board.get_property(pos)->get_property_name());
        QString rent=QString::number(game.board.get_property(pos)->get_rent(0));
        QString color=QString::fromStdString(game.board.get_property(pos)->get_color());
        QString name=QString::fromStdString(game.get_current_player()->get_name());

        emit updateProperty(property, color, rent, name);

    }
    emit updatePlayerCredits();
}

bool GameLogic::nextPlayer(){

    std::cout<<"=====================================\n=====================================\nEntered nextPlayer\n This round dices:";
    game.dice.get_dices();
    std::cout<<"=====================================\n=====================================\n";
    if(!game.dice.check_double()){
        game.next_player();
        if(game.get_current_player()==game.get_player(0)){
            if(game.get_current_player()->get_if_in_jail()){
                if(game.get_current_player()->get_turns_in_jail()==3){
                    game.get_current_player()->change_jail_status();
                    game.get_current_player()->set_position(10);
                    game.get_current_player()->reset_turns_in_jail();
                    emit myTurn();
                }
                else{
                    game.get_current_player()->add_turn_in_jail();
                    emit inJail();
                }
            }
            else
                emit myTurn();
        }
        else if(game.get_current_player()==game.get_player(1))
            emit nextPlayerDisable();
        qInfo()<<"True";
        return true;
    }
    else
        return false;
}

//For Signals
void GameLogic::onNextPlayerDisable(){
    qInfo()<<"Next player disabled";
}
void GameLogic::onDeleteGPlayer3()
{
    qInfo() << "Game: Player 3 deleted";
}
void GameLogic::onDeleteGPlayer4()
{
    qInfo() << "Game: Player 4 deleted";
}
void GameLogic::onMyTurn(){
    qInfo()<<"My turn";
}
logic::Game GameLogic::get_game(){
    return game;
}


int GameLogic::code_2_action(std::string message){
    qInfo()<<"Entered code_2_action";
    qInfo()<<"<<"<<message;
    std::string code = message.substr(0,message.find("_"));
    message.erase(0, message.find("_")+1);

    if(code=="22"){
        this->rollDice();
    }
    if(code=="23"){
        buyProperty();
    }
    if(code=="26"){
        getChanceCard();
    }
    if(code=="27"){
        getCommunityCard();
    }
    if(code=="29"){
        if(parse_info(&message)=="1"){
            game.get_current_player()->take_money(50);
            game.get_current_player()->change_jail_status();
            game.get_current_player()->reset_turns_in_jail();
        }
        if(parse_info(&message)=="2"){
            game.get_current_player()->change_jail_status();
            game.get_current_player()->reset_turns_in_jail();
        }
    }

    return std::stoi(code);
}

std::string GameLogic::parse_info(std::string *message){
    qInfo()<<"Entered parse_info";

    std::string delimiter = "_";
    std::string code = message->substr(0, message->find(delimiter));
    message->erase(0, message->find(delimiter)+delimiter.length());

    return code;
}

void GameLogic::buyHouse(QString property_name){
    qInfo()<<"Entered buyHouse";
    std::cout<<"Property name: "<<property_name.toStdString()<<std::endl;
    game.board.get_property_by_name(property_name.toStdString())->get_facul()->increase_level();
    game.get_current_player()->take_money(game.board.get_property_by_name(property_name.toStdString())->get_facul()->get_build_house_price());
    emit updatePlayerCredits();
}

void GameLogic::sellHouse(QString property_name){
    qInfo()<<"Entered sellHouse";
    game.board.get_property_by_name(property_name.toStdString())->get_facul()->decrease_level();
    game.get_current_player()->give_money(game.board.get_property_by_name(property_name.toStdString())->get_facul()->get_build_house_price()/2);
    emit updatePlayerCredits();
}

void GameLogic::mortgageProperty(QString property_name){
    qInfo()<<"Entered mortgageProperty";
    game.board.get_property_by_name(property_name.toStdString())->change_mortgage_status();
    game.get_current_player()->give_money(game.board.get_property_by_name(property_name.toStdString())->get_mortgage_price());
    emit updatePlayerCredits();
}

void GameLogic::unmortgageProperty(QString property_name){
    qInfo()<<"Entered unmortgageProperty";
    game.board.get_property_by_name(property_name.toStdString())->change_mortgage_status();
    game.get_current_player()->take_money(game.board.get_property_by_name(property_name.toStdString())->get_mortgage_price());
    emit updatePlayerCredits();
}

int GameLogic::getRent(QString property_name){
    qInfo()<<"Entered getRent";
    if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==FACULTY)
        return game.board.get_property_by_name(property_name.toStdString())->get_rent(game.dice.get_total());
    else if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==STATION)
        return game.board.get_property_by_name(property_name.toStdString())->get_rent(game.dice.get_total());
    else if(game.board.get_property_by_name(property_name.toStdString())->get_property_type()==UTILITY)
        return 0;
    return 0;
}

void GameLogic::onupdatePlayerscredits(){
    if(game.get_current_player()==game.get_player(0)){
        if(game.check_bankrupt(&game.board)){
            qInfo()<<"You are bankrupt";
        }
    }
}

int GameLogic::get_current_balance(){
    return game.get_current_player()->check_balance();
}

int GameLogic::get_prop_price(){
    return game.board.get_property(game.get_current_player()->get_position())->get_price();
}

QString GameLogic::getPlayerName(int id){
    return QString::fromStdString((game.get_player(id)->get_name()));
}

int GameLogic::get_number_of_players(){
    return game.number_players();
}


int GameLogic::getChanceCard(){
    srand(time(NULL));
    int random_card = rand() % 16;
    luck_chance_index=random_card;

    game.board.chance_cards[random_card]->action(game.player_list, game.get_current_player());
    emit updatePlayerCredits();
    emit updatePlayerPosition();

    if(game.get_current_player()->get_name()==game.get_player(0)->get_name()){
        QString consequence = QString::fromStdString(game.board.chance_cards[random_card]->get_consequence());
        emit chanceCommunityCard(consequence);
        return -1;
    }
    return random_card;
}

int GameLogic::getCommunityCard(){
    srand(time(NULL));
    int random_card = rand() % 16;
    luck_chance_index=random_card;

    game.board.community_chest_cards[random_card]->action(game.player_list, game.get_current_player());
    emit updatePlayerCredits();
    emit updatePlayerPosition();

    if(game.get_current_player()->get_name()==game.get_player(0)->get_name()){
        QString consequence = QString::fromStdString(game.board.community_chest_cards[random_card]->get_consequence());
        emit chanceCommunityCard(consequence);
        qInfo()<<"Community card consequence: "<<consequence;
        return -1;
    }
    return random_card;
}


void GameLogic::payBail(){
    if(game.get_current_player()->check_balance()>50){
        game.get_current_player()->take_money(50);
        game.get_current_player()->change_jail_status();
        game.get_current_player()->reset_turns_in_jail();
        emit updatePlayerCredits();
        emit myTurn();
    }
}

bool GameLogic::tryDouble(){
    game.dice.roll();
    if(game.dice.check_double()){
        game.get_current_player()->change_jail_status();
        game.get_current_player()->reset_turns_in_jail();
        emit myTurn();
        return true;
    }
    return false;
}
