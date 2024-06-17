#include "../include/logic/Player.h"
//#include "logic/Game.h"
#include <string>

// Path: src/Cards.h
using namespace logic;

// constructor
Player::Player(std::string player_name,std::string player_id, int player_model){
    name = player_name;
    id=player_id;
    model = player_model;
    position = 0;
    money = 1500;
    get_out_of_jail_card = 0;
    turns_in_jail = 0;
    num_of_houses = 0;
    num_of_hotels = 0;
    in_jail = false;
}

// function print_player
void Player::print_player(){
    std::cout << "Player name: " << name << std::endl;
    std::cout << "Player model: " << model << std::endl;
    std::cout << "Player position: " << position << std::endl;
    std::cout << "Player money: " << money << std::endl;
    std::cout << "Player get_out_of_jail_card: " << get_out_of_jail_card << std::endl;
    std::cout << "Player turns_in_jail: " << turns_in_jail << std::endl;
    std::cout << "Player in_jail: " << in_jail << std::endl;
}

// function to return current player
/*Player* Player::get_current_player() {
    //return the player
    return this;
}*/

// function to get the player's name
std::string Player::get_name() {
    //return the player's name
    return name;
}

// function to get the player's position
int Player::get_position() {
    //return the player's position
    return position;
}

//function to take money from the player
void Player::take_money(int amount) {
    money -= amount;
}

//function to give money to the player
void Player::give_money(int amount) {
    money += amount;
}

void Player::set_money(int amount) {
    money = amount;
}

//function to check the player's balance
int Player::check_balance() {
    return money;
}

//function to check if the player is bankrupt
bool Player::get_bankrupt() { 
    return bankrupt;
}

//function to set the player's bankrupt status
void Player::set_bankrupt() {
    bankrupt = true;
}


// function to use the get out of jail card
void Player::use_out_of_jail() {
    if (in_jail) {
        if (get_out_of_jail_card > 0) {
            get_out_of_jail_card--;
            in_jail = false;
        }
    }
}
void Player::set_position(int new_position) {
    position = new_position;
}

// function to know if player is in jail
bool Player::get_if_in_jail() {
    //return the player's position
    return in_jail;
}
void Player::go_to_jail(){
    this->in_jail=true;
    this->position=10;
    this->turns_in_jail=0;
}

// function to know how many houses player has
int Player::get_number_of_houses() {
    //return number of houses
    return num_of_houses;
}

// function to know how many hotels player has
int Player::get_number_of_hotels() {
    //return number of hotels
    return num_of_hotels;
}

//////LOGIC FOR Prison//////

void Player::add_get_out_of_jail_card(){
    this->get_out_of_jail_card++;
}
void Player::try_2_get_out_jail(){
    if (this->turns_in_jail>=3)
    {
        this->in_jail=false;
        this->turns_in_jail=0;
    }
    else{
        int option;
        logic::Dice dice;
        std::cout<<"You have 3 ways to get out of jail, which one do you want to try? \n1-Pay 50 ECTS.\n2-Try to get a double.\n3-Use a card, if you have one.\n4-Do nothing."<<std::endl;
        std::cin>>option;
        switch (option)
        {
        case 1:
            if (this->check_balance()>=50)
            {
                this->take_money(50);
                this->change_jail_status();
                this->turns_in_jail=0;
                
            }
            else{
                std::cout<<"You don't have this kind of money"<<std::endl;
                try_2_get_out_jail();
            }
            break;
        case 2:
            dice.roll();
            dice.get_dices();
            if(dice.check_double()){
                this->change_jail_status();
                this->turns_in_jail=0;
            }
            else
                this->turns_in_jail++;
            break;
        case 3:
            if(this->get_out_of_jail_card>0){
                this->get_out_of_jail_card--;
                this->in_jail=false;
                this->turns_in_jail=0;
            }
            else
            {
                std::cout<<"You don't have this type of card!"<<std::endl;
                try_2_get_out_jail();
            }
        case 4:
            this->turns_in_jail++;
                
            break;
        default:
            break;
        }
    }
}

// function to change the player's jail status
void Player::change_jail_status(){
    this->in_jail = !this->in_jail;
}

void Player::add_turn_in_jail(){
    this->turns_in_jail++;
}

void Player::reset_turns_in_jail(){
    this->turns_in_jail=0;
}

int Player::get_turns_in_jail(){
    return this->turns_in_jail;
}

