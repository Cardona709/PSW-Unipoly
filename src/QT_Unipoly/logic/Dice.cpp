#include "../include/logic/Dice.h"
#include <string>

// Path: src/Cards.h
using namespace logic;


//function to randomize the dice roll
void Dice::roll() {
    //create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    //return the random number
    dices[0] = dis(gen);
    dices[1] = dis(gen);
}

//function to check if the dice roll is a double
bool Dice::check_double() {
    //check if the dice roll is a double
    if (dices[0] == dices[1]) {
        return true;
    }
    return false;
}

//function to get the total of the dice roll
int Dice::get_total() {
    //return the total of the dice roll

    return dices[0] + dices[1];
}

//function to get the dice roll
void Dice::get_dices() {
    //return the dice roll
    std::cout << dices[0] << " " << dices[1] << std::endl;
}

