#include "../include/logic/Utility.h"
#include <string>

// Path: src/Utility.h
using namespace logic;

//function to change utility's level -- not done yet
void Utility::change_level(){
    if(this->level == 0)
        this->level = 1;
    else
        this->level = 0;
}

//function to get the property's rent price
int Utility::get_rent_price( int total_dice){
    if (level)  
        return total_dice*10; //both utilities owned
    else 
        return total_dice*4; 
}

//function to print utility's info
void Utility::print_utility(){
    std::cout << "Utility name: " << name << std::endl;
    std::cout << "Utility level: " << level << std::endl;
}

std::string Utility::get_name(){
    return this->name;
}

int Utility::get_buy_price(){
    return this->buy_price;
}

int Utility::get_mortgage(){
    return this->mortgage;
}
