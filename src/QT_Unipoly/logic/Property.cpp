#include "../include/logic/Property.h"
#include <string>

using namespace logic;

Property::Property(Player *Owner, int type, Faculty *facul, Station *station, Utility *util, int id)
{
    this->owner = Owner;
    this->type = type;
    this->facul = facul;
    this->station = station;
    this->util = util;
    this->id = id;
}

int Property::get_property_type()
{
    return this->type;
}

Player *Property::get_property_owner()
{
    return this->owner;
    // std::cout << "Property owner is " << this->owner->get_name() << std::endl;
}

Faculty *Property::get_facul()
{
    return this->facul;
}

Station *Property::get_station()
{
    return this->station;
}

Utility *Property::get_util()
{
    return this->util;
}

int Property::get_price()
{
    int typ = this->type;
    switch (typ)
    {
    case FACULTY:
        return this->get_facul()->get_buy_price();
        break;
    case STATION:
        return this->get_station()->get_buy_price();
        break;
    case UTILITY:
        return this->get_util()->get_buy_price();
        break;
    default:
        return 0;
        break;
    }
}

void Property::print_property()
{
    std::cout << "Property type: " << this->type << std::endl;
    int tipo = this->get_property_type();

    if (this->owner != nullptr)
    {
        switch (tipo)
        {
        case FACULTY:
            this->get_facul()->print_faculty();
            std::cout << "Property owner: " << this->owner->get_name() << std::endl;
            break;
        case STATION:
            this->get_station()->print_station();
            std::cout << "Property owner: " << this->owner->get_name() << std::endl;
            break;
        case UTILITY:
            this->get_util()->print_utility();
            std::cout << "Property owner: " << this->owner->get_name() << std::endl;
            break;
        default:
            break;
        }
    }
    else
    {
        std::cout << "Property " << this->get_property_name() << " has no owner" << std::endl;
    }
}

bool Property::buy_property(Player *new_owner, int type)
{
    std::cout<<"Entered buy property"<<std::endl;
    if (this->owner == nullptr)
    {
        switch (type)
        {
        case FACULTY:
            if (new_owner->check_balance() >= this->facul->get_buy_price())
            {
                new_owner->take_money(this->facul->get_buy_price());
                this->change_owner(new_owner);
                std::cout << "Property bought by " << this->owner->get_name() << std::endl;
                return true;
            }
            else
            {
                std::cout << "Not enough money to buy property" << std::endl;
                return false;
            }
            break;
        case STATION:
            if (new_owner->check_balance() >= this->station->get_buy_price())
            {
                new_owner->take_money(this->station->get_buy_price());
                this->change_owner(new_owner);
                std::cout << "Property bought by " << this->owner->get_name() << std::endl;
                return true;
            }
            else
            {
                std::cout << "Not enough money to buy property" << std::endl;
                return false;
            }
            break;
        case UTILITY:
            if (new_owner->check_balance() >= this->util->get_buy_price())
            {
                new_owner->take_money(this->util->get_buy_price());
                this->change_owner(new_owner);
                std::cout << "Property bought by " << this->owner->get_name() << std::endl;
                return true;
            }
            else
            {
                std::cout << "Not enough money to buy property" << std::endl;
                return false;
            }
            break;

        default:
            std::cout << "Not a valid property type to buy" << std::endl;
            break;
        }
    }
    else
    {
        std::cout << "Property already has an owner" << std::endl;
    }
    return false;
}

void Property::change_owner(Player *new_owner)
{
    // Player* old_owner = this->owner;
    this->owner = new_owner;

    std::cout << "Property  changed owner to " << this->owner->get_name() << std::endl;
    this->print_property();
    // depois  preciso tirar a property ao old_owner e dar ao new_owner
}

int Property::get_rent(int dice_value)
{
    int typ = this->type;
    switch (typ)
    {
    case FACULTY:
        return this->get_facul()->get_rent_price();
        break;
    case STATION:
        return this->get_station()->get_rent_price();
        break;
    case UTILITY:
        return this->get_util()->get_rent_price(dice_value);
        break;
    default:
        return 0;
        break;
    }
}

int Property::get_id()
{
    return this->id;
}

bool Property::get_if_mortgaged()
{
    return this->mortgaged;
}

void Property::change_mortgage_status()
{
    this->mortgaged = !this->mortgaged;
}

std::string Property::get_property_name()
{
    int typ = this->type;
    switch (typ)
    {
    case FACULTY:
        return this->get_facul()->get_name();
        break;
    case STATION:
        return this->get_station()->get_name();
        break;
    case UTILITY:
        return this->get_util()->get_name();
        break;
    default:
        return "Not a valid property";
        break;
    }
}

int Property::get_mortgage_price()
{
    int typ = this->type;
    switch (typ)
    {
    case FACULTY:
        return this->get_facul()->get_mortgage();
        break;
    case STATION:
        return this->get_station()->get_mortgage();
        break;
    case UTILITY:
        return this->get_util()->get_mortgage();
        break;
    default:
        return 0;
        break;
    }
}


bool Property::check_if_can_buy()
{
    if (this->get_property_owner() == NULL)
    {
        if(this->get_property_type()==FACULTY || this->get_property_type()==UTILITY || this->get_property_type()==STATION)
            return true;
        else
            return false;
    }
    else
        return false;
}

std::string Property::get_color()
{
    int typ = this->type;
    if(type==FACULTY){
        int color=this->get_facul()->get_color();
        switch (color) {
        case BROWN:
            return "Brown";
            break;
        case LIGHTBLUE:
            return "Light Blue";
            break;
        case PINK:
            return "Pink";
            break;
        case ORANGE:
            return "Orange";
            break;
        case RED:
            return "Red";
            break;
        case YELLOW:
            return "Yellow";
            break;
        case GREEN:
            return "Green";
            break;
        case DARKBLUE:
            return "Dark Blue";
            break;
        default:
            break;
        }
    }
    return "NULL";
}
