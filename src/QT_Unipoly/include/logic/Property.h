#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Faculty.h"
#include "Station.h"
#include "Utility.h"


#define BROWN 0
#define LIGHTBLUE 1
#define PINK 2
#define ORANGE 3
#define RED 4
#define YELLOW 5
#define GREEN 6
#define DARKBLUE 7

#define GO 0
#define CHANCE 1
#define COMMUNITY_CHEST 2
#define TAX 3
#define JAIL 4
#define GO_TO_JAIL 5
#define FREE_PARKING 6
#define FACULTY 7
#define STATION 8
#define UTILITY 9

namespace logic
{
    class Property
    {
    protected:
        Player *owner; // null if no owner
        int type;      // luck, community_chest, go_to_jail, free_parking, tax, jail dont have owner
        Faculty *facul;
        Station *station;
        Utility *util;
        int id;
        bool mortgaged = false; // false if not mortgaged, true if mortgaged
    public:
        Property(Player *Owner, int type, Faculty *facul, Station *station, Utility *util, int id); // constructor
        Player *get_property_owner();
        Faculty *get_facul();
        Station *get_station();
        Utility *get_util();
        virtual ~Property() = default;
        void print_property();
        std::string get_property_name();
        bool buy_property(Player *new_owner, int type);
        void change_owner(Player *new_owner);
        int get_property_type();
        int get_rent(int dice_value);
        int get_id();
        std::string get_color();
        bool get_if_mortgaged();
        int get_mortgage_price();
        void change_mortgage_status();
        int get_price();

        // Function to check if property can be bought
        // Return:
        //-True if property is not owned and;
        //-False if it is owned
        bool check_if_can_buy();
        void pay_rent(Player *player);

        // Property(); // default constructor
    };
}
