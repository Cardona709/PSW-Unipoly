#ifndef GAMEINIT_H
#define GAMEINIT_H
#include <iostream>
#include <vector>
#include <string>
#include <QObject>

// #include "include/logic/Dice.h"
// #include "include/logic/Board.h"
// #include "include/logic/Property.h"
// #include "include/logic/Player.h"
// #include "include/logic/Faculty.h"
// #include "include/logic/Station.h"
//#include "include/logic/Utility.h"
#include "include/logic/Game.h"
//#include "include/logic/Cards.h"



class GameLogic : public QObject
{
    class init_info{
    public:
        std::string name;
        std::string id;
    public:
        init_info(std::string name, std::string id){
            this->name=name;
            this->id=id;
        }
    };

    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = nullptr);
    std::vector<init_info> players;
    int numberofplayers;
    int code_2_action(std::string code);
    std::string parse_info(std::string *message);
    QString property;
    int luck_chance_index;

private:
    logic::Game game;

signals:
    void onstartGame();
    void myTurn();
    void nextPlayerDisable();
    void deleteGPlayer3();
    void deleteGPlayer4();
    void updatePlayerCredits();
    void updatePlayerPosition();
    void updateProperty(const QString &property,const QString &color, const QString &rent, const QString &name);
    void updatePlayerName();
    void chanceCommunityCard(const QString &consequence);
    void inJail();

private slots:
    void onNextPlayerDisable();
    void onDeleteGPlayer3();
    void onDeleteGPlayer4();

public slots:
    void saveinfo(QString id, QString name);
    void deleteinfo(QString id);
    void set_n_players(int number);
    int get_number_of_players();
    void startGame();
    QString getPlayerCredits(int player_number);
    int getPlayerPosition(int player_number);
    void rollDice();
    QString getProperty();
    QString getprice();
    void buyProperty();
    bool nextPlayer();
    void onMyTurn();
    logic::Game get_game();
    int get_prop_price();
    QString getPlayerName(int id);
    int getHouses(QString property_name);
    int getBuildHousePrice(QString property_name);
    bool getMortgage_status(QString property_name);
    int getRent(QString property_name);

    void mortgageProperty(QString property_name);
    void unmortgageProperty(QString property_name);
    void sellHouse(QString property_name);
    void buyHouse(QString property_name);
    void onupdatePlayerscredits();
    int get_current_balance();
    int getChanceCard();
    int getCommunityCard();

    //try to get out of jail
    void payBail();
    bool tryDouble();



};



#endif // GAMEINIT_H
