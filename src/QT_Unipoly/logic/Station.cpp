#include "../include/logic/Station.h"
#include <string>

// Path: src/Station.h
using namespace logic;

void Station::print_station(){
    std::cout << "Station name: " << name << std::endl;
    std::cout << "Station level: " << level << std::endl;
    std::cout << "Station rent: " << this->get_rent_price() << std::endl;
}

// //function to change Station's level -- not done yet
 void Station::increase_level(){
    if (this->level <=2)
    {
        this->level++;
    }
}

void Station::decresase_level(){
    if (this->level>=1)
    {
        this->level--;
    }
}


// //function to get the property's rent price
int Station::get_rent_price(){
     return rent_price[level];
}

std::string Station::get_name(){
    return this->name;
}

int Station::get_buy_price(){
    return this->buy_price;
}
int Station::get_mortgage(){
    return this->mortgage;
}
