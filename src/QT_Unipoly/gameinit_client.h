#ifndef GAMEINIT_CLIENT_H
#define GAMEINIT_CLIENT_H

#include <QObject>
#include <iostream>
#include <vector>
#include <string>

// #include "include/logic/Dice.h"
// #include "include/logic/Board.h"
// #include "include/logic/Property.h"
// #include "include/logic/Player.h"
// #include "include/logic/Faculty.h"
// #include "include/logic/Station.h"
// #include "include/logic/Utility.h"
#include "include/logic/Game.h"
//#include "include/logic/Cards.h"

class GameInit_Client : public QObject
{
    Q_OBJECT
public:
    explicit GameInit_Client(QObject *parent = nullptr);
    void create_game();
    int numberofplayers;
    int code_2_action(std::string code);
    std::string parse_info(std::string *message);
    void set_myname(std::string name);

signals:
    void init_Game();
    void myTurn();
    void nextPlayerDisable();
    void wantToBuy();
    void close();
    void updatePlayerCredits();
    void deleteGPlayer3();
    void deleteGPlayer4();
    void deletePlayer3();
    void deletePlayer4();
    void updatePlayerPosition();
    void updatePlayerName();
    void updateProperty(const QString &property,const QString &color, const QString &rent, const QString &name);
    void chanceCommunityCard(const QString &consequence);
    void inJail();


public slots:
    void onInit_Game();
    void onMyTurn();
    void onNextPlayerDisable();
    void inhere();
    void onWantToBuy();
    QString getProperty();
    QString getprice();
    std::string get_myname();
    logic::Game get_game();
    void onClose();
    int get_number_of_players();
    QString getPlayerName(int id);
    QString getMyName_qstring();
    QString getPlayerCredit(int player_number);
    int getPlayerPosition(int player_number);
    int getRent(QString property_name);
    int getHouses(QString property_name);
    bool tryDouble();
    int get_current_balance();

private:
    logic::Game game;
    std::vector<std::string> players;
    std::string my_name;


};

#endif // GAMEINIT_CLIENT_H
