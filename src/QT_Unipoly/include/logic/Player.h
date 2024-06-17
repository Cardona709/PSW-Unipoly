#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../../include/logic/Dice.h"

//#include "Property.h"

namespace logic {
    class Player {
        public:
            void print_player();
            std::string get_name();
            int get_position();
            void take_money(int amount); // acrescentar int amount no class diagram
            void give_money(int amount); // acrescentar int amount no class diagram
            void set_money(int amount); // acrescentar int amount no class diagram
            int check_balance();
            bool get_bankrupt();
            void set_bankrupt();
            void set_position(int new_position);
            //void add_property(Property *property); // acrescentar Property *property no class diagram
            //void remove_property(Property *property); // acrescentar Property *property no class diagram
            void use_out_of_jail();
            Player(std::string name, std::string id ,int model); // constructor
            //Player* get_player();
            int get_number_of_houses();
            int get_number_of_hotels();
            void add_get_out_of_jail_card();
            //Jail logic
            bool get_if_in_jail();
            void try_2_get_out_jail();
            void change_jail_status(); // 0 for getting in, 1 for getting out
            void go_to_jail();
            void add_turn_in_jail();
            int get_turns_in_jail();
            void reset_turns_in_jail();

        private:
            //std::vector<std::vector<Property*>> properties; 
            int get_out_of_jail_card;
            int turns_in_jail; 
            bool in_jail;
            bool bankrupt;

        protected:
            std::string name;
            std::string id;
            int model;
            int position;
            int money;
            int num_of_houses;
            int num_of_hotels;
        };


}


