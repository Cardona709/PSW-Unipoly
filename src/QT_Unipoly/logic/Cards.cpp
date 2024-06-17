#include <iostream>
#include <vector>
#include <string>

#include "../include/logic/Cards.h"
#include "../include/logic/Player.h"
#include "../include/logic/Game.h"

using namespace logic;

// Constructor
ChanceCard::ChanceCard(std::string name, int type, std::string consequence) {
    this->name = name;
    this->type = type;
    this->consequence = consequence;
}

std::string ChanceCard::get_name() {
    return this->name;
}

int ChanceCard::get_type() {
    return type;
}

std::string ChanceCard::get_consequence() {
    return consequence;
}

void ChanceCard::action(std::vector<Player*> player_list, Player* curr_player) {
    switch (type) {
    case 0: {// Advance to Go 
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->set_position(0);}
        break;
    case 1: {// Advance to FEP
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        if(curr_player->get_position() > 24) // this means it has to pass by Go
            curr_player->give_money(200);     
        curr_player->set_position(24);
        }break;
    case 2: {// Advance to FEUP
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->set_position(39);}
        break;
    case 3: {// Advance to IPAM
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        if(curr_player->get_position() > 11) // this means it has to pass by Go
            curr_player->give_money(200);
        curr_player->set_position(11);
    }break;
    case 4: case 5: // Advance to the nearest Station
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        if(curr_player->get_position() == 7)
            curr_player->set_position(15);
        else if(curr_player->get_position() == 22)
            curr_player->set_position(25);
        else if(curr_player->get_position() == 36)
            curr_player->set_position(5);
        break; 
    case 6: {// Advance to the nearest Utility
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        if(curr_player->get_position() == 7 || curr_player->get_position() == 36)
            curr_player->set_position(12);
        else if(curr_player->get_position() == 22)
            curr_player->set_position(28);}
        break;
    case 7: // Bank pays you dividend
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(50);
        break;
    case 8: // Get out of Praxis free
        std::cout << "Player got: " << name << "\n"
                  << consequence << std::endl;
        if (curr_player->get_if_in_jail()) 
            curr_player->change_jail_status();
        break;
    case 9: // Go back 3 spaces
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->set_position((curr_player->get_position() - 3));
        break;
    case 10: // Go to Praxis
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->go_to_jail();
        break;
    case 11: // Make general repairs on all your property
        std::cout << "" << name << "\n"
                  << consequence << std::endl;
        //if(curr_player->is_bankrupt())

        curr_player->take_money(25 * curr_player->get_number_of_houses() + 100 * curr_player->get_number_of_hotels());
        break;
    case 12: // Pay transportation fee of ECTS 15
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->take_money(15);
        break;
    case 13: // Take a trip to Trindade
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->set_position(5);
        break;
    case 14: // You have been elected Chairman of the Board
        std::cout << "Player must: " << name << "\n"
                << consequence << std::endl; 
        // Give ECTS 50 to all players except the current one
        for(int i = 0; i < int(player_list.size()); i++){
            if(player_list[i] != curr_player){
                curr_player->take_money(50);
                player_list[i]->give_money(50);
            }
        }
        break;
    case 15:  // Your building loan matures
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(150);
        break;
    }
}

CommunityChestCard::CommunityChestCard(std::string card_name, int card_type, std::string card_consequence) {
    name = card_name;
    type = card_type;
    consequence = card_consequence;
}

std::string CommunityChestCard::get_name() {
    return name;
}

int CommunityChestCard::get_type() {
    return type;
}

std::string CommunityChestCard::get_consequence() {
    return consequence;
}

void CommunityChestCard::action(std::vector<Player*> player_list, Player* curr_player) {
    switch (type) {
    case 0: // Advance to Go
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->set_position(0);
        break;
    case 1: // Bank error in your favor
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(200);
        break;
    case 2: // School material fees
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->take_money(50);
        break;
    case 3: // Sale of stock
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(50);
        break;
    case 4: // Get out of Praxis free
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        if (curr_player->get_if_in_jail())
            curr_player->change_jail_status();
        break;
    case 5: // Go to Praxis
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->set_position(10);
        break;
    case 6: // Holiday fund matures
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(100);
        break;
    case 7: // Tuition fee refund
        std::cout << "Player must: " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(20);
        break;
    case 8: // Graduation day
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        // collect money from every player
        for(int i = 0; i < int(player_list.size()); i++){
            if(player_list[i] != curr_player)
                player_list[i]->take_money(10);}
        curr_player->give_money(10 * (player_list.size() - 1));
        break;
    case 9: // Life insurance matures
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(100);
        break;
    case 10: // Pay hospital fees
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->take_money(100);
        break;
    case 11: // School insurance fees
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->take_money(50);
        break;
    case 12: // Receive ECTS 25 consultancy fee
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(25);
        break;
    case 13: // Street repairs
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->take_money(40 * curr_player->get_number_of_houses() + 115 * curr_player->get_number_of_hotels());
        break;
    case 14: // Spelling bee
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(10);
        break;
    case 15: // Inherit ECTS 100
        std::cout << " " << name << "\n"
                  << consequence << std::endl;
        curr_player->give_money(100);
        break;
    }
}
