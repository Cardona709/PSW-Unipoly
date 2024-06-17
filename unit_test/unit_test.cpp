#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "../include/logic/Player.h"
#include "../include/logic/Game.h"
#include <gtest/gtest.h>

//test player name retrieval
TEST(gameLogic, playerCreation) {
    std::string name = "John Smith";
    logic::Player* p1=new logic::Player(name, 1);
    EXPECT_EQ(
        1500,
        p1->check_balance()
    );

    EXPECT_EQ(
        name,
        p1->get_name()
    );
}

//chcks if a player receives money when passing go
TEST(gameLogic, checkGo) {
    logic::Game game;
    logic::Board board = game.board;
    board.create_board();

    logic::Player* p1=new logic::Player("John Smith", 1);
    game.add_player(p1);

    EXPECT_EQ(
        "John Smith",
        game.get_current_player()->get_name()
    );

    game.move_current_player(40);
    EXPECT_EQ(
        0,
        p1->get_position()
    );
    EXPECT_EQ(
        1700,
        p1->check_balance()
    );
}

//test dice roll
TEST(Roll_Dice_4, Roll_dice_4A) {
    logic::Dice dice;
    dice.roll();
    
    EXPECT_TRUE(
        dice.get_total() <= 12 && dice.get_total() >= 2 && dice.dices[0] <= 6 && dice.dices[0] >= 1 && dice.dices[1] <= 6 && dice.dices[1] >= 1
    );

    dice.dices[1] = dice.dices[0];

    EXPECT_TRUE(
        dice.check_double() == true
    );
}

//test property buy
TEST(Buy_A_Property_8, Buy_Property_8A) {
    logic::Game game;
    
    logic::Board board = game.board;
    board.create_board();

    logic::Player* p1=new logic::Player("John Smith", 1);
    game.add_player(p1);
    p1->set_position(1);
    logic::Property* test_property = board.get_property(p1->get_position());
    test_property->buy_property(p1, test_property->get_property_type());

    //check is bought property belongs to proper player
    EXPECT_EQ(
        p1,
        board.get_property(1)->get_property_owner()
    );

    //check if player has less money after buying property
    int test_price;

    if(test_property->get_property_type() == 7)
    {
        test_price = test_property->get_facul()->get_buy_price();
    }
    else if(test_property->get_property_type() == 8)
    {
        test_price = test_property->get_station()->get_buy_price();
    }
    else if(test_property->get_property_type() == 9)
    {
        test_price = test_property->get_util()->get_buy_price();
    }
    EXPECT_EQ(
        1500 - test_price,
        p1->check_balance()
    );
}

//test player change
TEST(playerManagement, playerChange) {
    logic::Game game;
    logic::Board board = game.board;
    board.create_board();

    logic::Player* p1=new logic::Player("John Smith", 1);
    game.add_player(p1);
    logic::Player* p2=new logic::Player("Jane Doe", 2);
    game.add_player(p2);

    EXPECT_EQ(
        p1,
        game.get_current_player()
    );

    game.next_player();

    EXPECT_EQ(
        p2,
        game.get_current_player()
    );
}

//test player deletion 
TEST(playerManagement, playerDeletion) {
    logic::Game game;
    logic::Board board = game.board;
    board.create_board();

    logic::Player* p1=new logic::Player("John Smith", 1);
    game.add_player(p1);
    logic::Player* p2=new logic::Player("Jane Doe", 2);
    game.add_player(p2);

    EXPECT_EQ(
        p1,
        game.get_current_player()
    );

    game.next_player();

    EXPECT_EQ(
        p2,
        game.get_current_player()
    );

    game.delete_players();

    EXPECT_EQ(
        0,
        game.number_players()
    );

    EXPECT_EQ(
        NULL,
        game.get_current_player()
    );

    EXPECT_EQ(
        NULL,
        game.get_player(0)
    );

    EXPECT_EQ(
        NULL,
        game.get_player(1)
    );

    game.print_players();
}

//test player insertion in game

TEST(playerManagement, playerInsertion) {
    logic::Game game;
    logic::Board board = game.board;
    board.create_board();


    logic::Player* p1=new logic::Player("John Smith", 1);
    game.add_player(p1);
    EXPECT_EQ(
        p1,
        game.get_player(0)
    );

    //test duplicate
    logic::Player* p2=new logic::Player("John Smith", 2);
    game.add_player(p2);
    EXPECT_EQ(
        NULL,
        game.get_player(1)
    );

    p2=new logic::Player("Jane Doe", 2);
    game.add_player(p2);
    EXPECT_EQ(
        p2,
        game.get_player(1)
    );

    game.print_players();
}
