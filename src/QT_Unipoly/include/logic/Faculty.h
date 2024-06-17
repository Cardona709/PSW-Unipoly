#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace logic
{

    class Faculty
    {
    public:
        Faculty(std::string name, int buy_price, int mortgage, std::vector<int> rent_price, int color, int build_house_price)
        {
            this->name = name;
            this->buy_price = buy_price;
            this->level = 0;
            this->mortgage = mortgage;
            this->rent_price = rent_price;
            this->color = color;
            this->build_house_price = build_house_price;
        }
        void increase_level();
        void decrease_level();
        void print_faculty();
        std::string get_name();
        int get_rent_price();
        int get_build_house_price();
        int get_buy_price();
        int get_level();
        int get_mortgage();
        int get_color();

    private:
        std::string name;
        int buy_price;
        int level;
        int mortgage;
        std::vector<int> rent_price;
        int color;
        int build_house_price;
    };
} // namespace logic
