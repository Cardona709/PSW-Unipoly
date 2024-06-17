#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace logic {

class Utility{
    public:
        Utility(std::string name){
            this->name = name;
            this->level = 0;
        }
        void change_level();
        std::string get_name();
        int get_rent_price(int dice);
        void print_utility();
        int get_buy_price();
        int get_mortgage();
    private:
        std::string name;
        bool level=false; // 0 for base, 1 for both Utilities owned
        int mortgage = 75;
        int buy_price = 150;
};
}   // namespace logic