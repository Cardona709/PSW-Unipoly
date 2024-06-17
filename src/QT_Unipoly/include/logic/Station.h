#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace logic {

class Station{
    public:
        // constructor
        Station(std::string name){
            this->name = name;
            this->level = 0;
        }
        void print_station();
        void increase_level(); 
        void decresase_level();
        std::string get_name();
        int get_rent_price(); 
        int get_buy_price();
        int get_mortgage();
    private:
        std::string name;
        int level; // number of stations owned - 1
        int mortgage = 100;
        int buy_price = 200;
        int rent_price[4] = {25, 50, 100, 200};
};
}   // namespace logic