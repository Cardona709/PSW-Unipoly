#include "../include/logic/Game.h"
#include <string>
#include <vector>

using namespace logic;

//function to create a new player

//add player to list of players
void Game::add_player(Player *player) {
    for (size_t i = 0; i < player_list.size(); i++) {
        if (player_list[i]->get_name() == player->get_name()) {
            std::cout << "Player already exists" << std::endl;
            return;
        }
    }
    player_list.push_back(player);
}

int Game::number_players() {
    return this->player_list.size();
}

void Game::print_players() {
    std::cout <<"========================="<< "Players in game"<<"========================="<< std::endl;
    for (size_t i = 0; i < player_list.size(); i++) {
        std::cout << "Player " << i+1 << std::endl;
        player_list[i]->print_player();
        std::cout <<"========================="<< std::endl;
    }
}


void Game::create_player(std::string name,std::string id, int model) {
    for (size_t i = 0; i < player_list.size(); i++) {
        if (player_list[i]->get_name() == name) {
            std::cout << "Player already exists" << std::endl;
            return;
        }
    }
    Player *player = new Player(name, id, model);
    add_player(player);
}

void Game::delete_players() {
    for (size_t i = 0; i < player_list.size(); i++) {
        player_list[i] = NULL;
    }
    player_list.vector::clear();
}

void Game::next_player() {
    if (current_player == static_cast<int>(player_list.size()-1)) {
        current_player = 0;
    } else {
        current_player++;
    }
    std::cout<<"Current Player"<<current_player<<std::endl;
    print_players();
    // while(get_current_player()->get_bankrupt())
    //     next_player();
}

Player* Game::get_current_player() {
    return player_list[current_player];
}

bool Game::check_win() {
    int players_left = 0;
    for ( size_t i = 0; i < player_list.size(); i++) {
        if (!player_list[i]->get_bankrupt()) {
            players_left++;
        }
    }
    if (players_left == 1) {
        return true;
    } else {
        return false;
    }
}

void Game::move_current_player(int places_2_move) {
    int new_position = player_list[current_player]->get_position() + places_2_move;
    if (new_position > 39) {
        new_position -= 40;
        player_list[current_player]->give_money(200);
    }
    if(new_position == 4) {
        player_list[current_player]->take_money(200);
    }
    if(new_position == 38) {
        player_list[current_player]->take_money(100);
    }
    this->get_current_player()->set_position(new_position);
}

Player* Game::get_player(int player_number) {
    return player_list[player_number];
}

Player* Game::get_player_by_name(std::string name) {
    for (size_t i = 0; i < player_list.size(); i++) {
        if (player_list[i]->get_name() == name) {
            return player_list[i];
        }
    }
    return NULL;
}



bool Game::in_property(Board *board){
    logic::Property* landed_property;
    int menu_input;
    landed_property = board->get_property(this->get_current_player()->get_position());

    if (landed_property->check_if_can_buy())
    {
        std::cout << "Do you want to buy this property? (" << std::endl << "1 - Yes\n2 - No" << std::endl;
        std::cin >> menu_input;
        if ((menu_input) == 1) {
            landed_property->buy_property(this->get_current_player(), landed_property->get_property_type());
            if(!this->dice.check_double()){
                this->next_player();
            }
            return true;
        }
        else {
            std::cout << "Property not bought\n" << std::endl;
            if(!this->dice.check_double()){
                this->check_bankrupt(board);
                this->next_player();
            }
            return true;
        }
    }
    else
    {
        std::cout << "This property is owned by " << landed_property->get_property_owner()->get_name() << std::endl;
        int rent=landed_property->get_rent(this->dice.get_total());
        if(landed_property->get_if_mortgaged()==true)
        {
            std::cout<<"This property is mortgaged"<<std::endl;
        }
        else{
            std::cout << "You have to pay " << rent << std::endl;
            this->get_current_player()->take_money(rent);
            landed_property->get_property_owner()->give_money(rent);
        }
        if(!this->dice.check_double()){
            this->check_bankrupt(board);
            this->next_player();
        }

        return true;
    }
}
void Game::check_properties(Board *board){
    int choice;
    int n_house = 0;
    int id = 100;
    int price = 0, decision = 0, p_id = 0;
    std::vector<int> ids;

    std::cout<<"\t1 - Check your properties\n\t2 - Improve a property (buy a Residence/Hotel)\n\t3 - Worsen a property (sell a Residence/Hotel)\n\t4 - Mortgage a property\n\t5 - Unmortgage a property\n\t6 - Sell a Property"<<std::endl;
    std::cin>>choice;
    switch (choice)
    {
    case 1://check properties owned by the player
        board->check_properties(get_current_player());   
        break;

    case 2://buy a residence/hotel
        std::cout<<"Which property would you like to improve?"<<std::endl;
        ids=board->check_prop_improve(get_current_player());
        if (ids.size() == 0)
        {
            std::cout<<"You don't have any property to improve"<<std::endl;
            break;
        }
        
        std::cout<<"Choose the property ID you want to improve: ";
        std::cin>>id;
        id=propper_id(ids,id);
        if(id==-1)
            break;
        while (1)
        {
            std::cout<<"How many houses would you want to buy? ";
            std::cin>>n_house;
            if (board->get_property(id)->get_facul()->get_level() == 5)
            {
                std::cout<<" The faculty is already level 5, you can't build more houses/hotels "<<std::endl;
                break;
            }
            else if(n_house <1 || n_house>5)
                std::cout<<"Invalid number of houses"<<std::endl;
            else if(n_house + board->get_property(id)->get_facul()->get_level() >5)
                std::cout<<"You can only upgrade your faculty to level 5 (hotel)"<<std::endl;
            else if (get_current_player()->check_balance()<board->get_property(id)->get_facul()->get_build_house_price()*n_house)
            {
               std::cout<<"You don't have enough money to buy "<<n_house<<" houses"<<std::endl;
               n_house=0;
               std::cout<<"You can buy a maximum of "<<get_current_player()->check_balance()/board->get_property(id)->get_facul()->get_build_house_price()<<" houses"<<std::endl;
            }
            else break;
        }
        for (int i = 0; i < n_house; i++)
        {
            board->get_property(id)->get_facul()->increase_level();
        }
        get_current_player()->take_money(board->get_property(id)->get_facul()->get_build_house_price()*n_house);
        std::cout<<"Improve the level of "<< board->get_property(id)->get_facul()->get_name() << " to " << board->get_property(id)->get_facul()->get_level()<<std::endl;
        break;
    case 3:///sell a residence/hotel
        std::cout<<"Which property's houses and hotels you would you like to sell"<<std::endl;
        ids=board->check_prop_improve(get_current_player());
        if (ids.size()==0)
        {
            std::cout<<"You don't have any houses nor hotels"<<std::endl;
            break;
        }
        
        std::cout<<"Choose the property ID you want to sell houses/ hotels: ";
        std::cin>>id;
        id=propper_id(ids,id);
        if(id==-1)
            break;
        while (1)
        {
            std::cout<<"How many houses would you like to sell? ";
            std::cin>>n_house;
            if (board->get_property(id)->get_facul()->get_level() == 0)
            {
                std::cout<<" The faculty doesn't have any constructions, if you really need money, try selling the faculty "<<std::endl;
                break;
            }
            else if(n_house <1 || n_house>5)
                std::cout<<"Invalid number of houses to sell"<<std::endl;
            else if(n_house > board->get_property(id)->get_facul()->get_level())
                std::cout<<" You can't sell "<< n_house <<"houses, your property has only " << board->get_property(id)->get_facul()->get_level()<<std::endl;
            else break;
        }
        for (int i = 0; i < n_house; i++)
        {
            board->get_property(id)->get_facul()->decrease_level();
        }
        get_current_player()->take_money(board->get_property(id)->get_facul()->get_build_house_price()*n_house);
        std::cout<<"Worsen the level of "<< board->get_property(id)->get_facul()->get_name() << " to " << board->get_property(id)->get_facul()->get_level()<<std::endl;
        break;
    case 4://mortgage a property
        std::cout<<"Which property would you like to mortgage?"<<std::endl;
        ids=board->check_prop_mortgage(get_current_player());
        if (ids.size()==0)
        {
            std::cout<<"You don't have any property to mortgage"<<std::endl;
            break;
        }

        std::cout<<"Choose the property ID you want to mortgage: ";
        std::cin>>id;
        id=propper_id(ids,id);
        if(id==-1)
            break;

        board->mortgage_prop(get_current_player(),id);

        break;
    case 5://unmortgage a property
        std::cout<<"Which property would you like to unmortgage?"<<std::endl;
        ids=board->check_prop_unmortgage(get_current_player());
        if (ids.size()==0)
        {
            std::cout<<"You don't have any property to unmortgage"<<std::endl;
            break;
        }

        std::cout<<"Choose the property ID you want to unmortgage: ";
        std::cin>>id;
        id=propper_id(ids,id);
        if(id==-1)
            break;

        board->unmortgage_prop(get_current_player(),id);
        break;
    case 6://sell a property to another player
        std::cout<< "Which property do you want to sell?"<<std::endl;
        ids=board->check_prop_mortgage(get_current_player());
        if (ids.size()==0)
        {
            std::cout<<"You don't have any property to sell"<<std::endl;
            break;
        }

        std::cout<<"Choose the property ID you want to sell: ";
        std::cin>>id;
        id=propper_id(ids,id);
        if(id==-1)
            break;

        std::cout<<"Which player do you want to sell the property to?"<<std::endl;

        for (int i = 0; i < number_players(); i++)
        {
            if (get_player(i)->get_name()!=get_current_player()->get_name())
            {
                std::cout<<"\t"<<i<<" - "<<get_player(i)->get_name()<<std::endl;
                ids.push_back(i);
            }
        }
        std::cout<<"Choose the player ID you want to sell the property to: ";
        while(1)
        {
            std::cin>>p_id;
            if(p_id > (number_players() -1) || p_id < 0)
                std::cout<<"Invalid ID, try again"<<std::endl;
            else
                break;
        }
        id=propper_id(ids,id);
        if(id==-1)
            break;
        if (get_player(p_id)->get_bankrupt())
        {
            std::cout<<"The player you choose, "<<get_player(p_id)->get_name() << "is bankrupt"<<std::endl;
            break;
        }
        else std::cout<<"The player you choose, "<<get_player(p_id)->get_name() << " only has "<< get_player(p_id)->check_balance()<<std::endl<<"How much do you want to sell the property for? ";
        std::cin>>price;
        if (price == -1)
            break;
        else if(price>get_player(p_id)->check_balance())
            {
                std::cout<<"The player doesn't have enough money to buy the property"<<std::endl;
                break;
            }
        std::cout<<get_player(p_id)->get_name()<< ", do you want to buy this property?\n1-Yes\n2-No\n";
        std::cin>>decision;
        switch (decision)
        {
        case 1:
                get_player(p_id)->take_money(price);
                get_current_player()->give_money(price);
                board->get_property(id)->change_owner(get_player(p_id));
                std::cout<<"The property now belongs to "<<get_player(p_id)->get_name()<<std::endl;
                break;
        case 2:
            std::cout<<"The player decline the offer!"<<std::endl;
            break;
            default:
            break;
        }
        
        




        break;
    
    default:
        break;
    }

}

int Game::propper_id(std::vector<int>& nums, int id){
    int flag=0; 
    while (flag==0)
        {
            if(id==-1)
                return -1;
            for (size_t i = 0; i < nums.size(); i++)
            {
                if (id==nums[i])
                {
                    flag=1;
                    break;
                }
            }
            if (flag==0)
            {
                std::cout<<"Invalid ID"<<std::endl;
                std::cout<<"Choose a proper ID: ";
                std::cin>>id;
            }
        }
    return id;
}

bool Game::check_bankrupt(Board *board)
{
    //check if the player is bankrupt
    //if yes, remove the player from the game
    //if no, continue the game
    if (get_current_player()->check_balance()<0)
        return true;
    else
        return false;
} 
