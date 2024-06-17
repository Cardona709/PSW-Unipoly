#include "../include/logic/Faculty.h"
#include <string>

// // Path: src/Faculty.h
using namespace logic;

// function to change property's level -- not done yet
void Faculty::increase_level()
{
    if (this->level < 5)
    {
        this->level++;
    }
}
void Faculty::decrease_level()
{
    if (this->level >= 1)
    {
        this->level--;
    }
}

// function to get the property's rent price
int Faculty::get_rent_price()
{
    return rent_price[level];
}

// function to get the property's build house price
int Faculty::get_build_house_price()
{
    return build_house_price;
}

void Faculty::print_faculty()
{
    std::cout << "Faculty name: " << name << std::endl;
    std::cout << "Faculty buy price: " << buy_price << std::endl;
    std::cout << "Faculty mortgage: " << mortgage << std::endl;
    std::cout << "Faculty rent price: " << this->get_rent_price() << std::endl;
    // std::cout << "Faculty color: " << color << std::endl;
}

std::string Faculty::get_name()
{
    return this->name;
}

int Faculty::get_buy_price()
{
    return this->buy_price;
}

int Faculty::get_level()
{
    return this->level;
}

int Faculty::get_mortgage()
{
    return this->mortgage;
}

int Faculty::get_color()
{
    return this->color;
}
