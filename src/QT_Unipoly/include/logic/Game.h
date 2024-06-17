#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Player.h"
#include "Dice.h"
#include "Player.h"
#include "Board.h"
#include "Property.h"
//#include "Cards.h"

namespace logic {
    

class Game {
    public:
        void kick_player(Player *Player);
        void reset_game();
        Player *get_current_player();
        bool check_win();
        void next_player();
        void move_current_player(int places_2_move);
        bool check_triple();
        void delete_players();
        void create_player(std::string name,std::string id, int model);
        int number_players();
        void set_player_char();
        void add_player(Player *player);
        void print_players();
        Player* get_player(int player_number);
        Player* get_player_by_name(std::string name);
        bool in_property(Board *board);
        std::vector<Player*> player_list;
        Dice dice;
        Board board;
        //bool end_game();
        //ingame logic
        //void CheckProperties();
        void check_properties(Board *board); //old option2
        int propper_id(std::vector<int>& nums, int id);
        bool check_bankrupt(Board *board);
    private:
        //std::vector<Card*> *card_list;
        int current_player=0;
        int houses;

    };
}
