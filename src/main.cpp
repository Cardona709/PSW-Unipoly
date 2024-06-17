#include <iostream>
#include <vector>
#include <string>

#include "QT_Unipoly/include/logic/Dice.h"
#include "QT_Unipoly/include/logic/Board.h"
#include "QT_Unipoly/include/logic/Property.h"
#include "QT_Unipoly/include/logic/Player.h"
#include "QT_Unipoly/include/logic/Faculty.h"
#include "QT_Unipoly/include/logic/Station.h"
#include "QT_Unipoly/include/logic/Utility.h"
#include "QT_Unipoly/include/logic/Game.h"
#include "QT_Unipoly/include/logic/Cards.h"


int main()
{
    std::cout << "Hello, Welcome to  Unipoly!" << std::endl;
    std::cout << "===================================" << std::endl;

    //input for how many player will be playing
    int num_players;
    while (1)
    {
        std::cout << "How many players will be playing? (2-4)" << std::endl;
        std::cin >> num_players;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        else if (num_players >= 2 && num_players <= 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid number of players" << std::endl;
        }
    }
    
    
    std::cout << "===================================" << std::endl;

    logic::Game game;
    std::string menu_input;

    //input for player's name
    std::string name_input;
    for (int i = 0; i < num_players; i++)
    {
        std::cout << "Player " << i + 1 << " name: " << std::endl;
        std::cin >> name_input;
        for (int j = 0; j < i; j++)
        {
            if (game.get_player(j)->get_name() == name_input)
            {
                std::cout << "Name already taken" << std::endl;
                i--;
                break;
            }
        }
        std::cout << "===================================" << std::endl;
        game.create_player(name_input, i + 1);
    }

    logic::Board board = game.board;
    board.create_board();
    board.print_board();

    board.get_property(1)->buy_property(game.get_player(0), FACULTY);
    board.get_property(3)->buy_property(game.get_player(0), FACULTY);
    
    game.print_players();
    std::cout << "===================================" << std::endl;
    
    // random value for card between 0 and 15
    int random_card;

    while(!game.check_win()){
        //std::cin.get();
        //system("clear");
        std::cout << "\033[33m================Player's Positions===================" << std::endl;
        for (int i = 0; i < num_players; i++)
        {
            std::cout << "Player"<< i+1 << ": " << game.get_player(i)->get_position()<<" | ";
        }
        std::cout<< std::endl;
        std::cout << "======================================================" << std::endl;
        if (game.get_current_player()->get_name() == "a")
        {
            std::cout<<"\033[31m" <<game.get_current_player()->get_name() << "'s turn:" << std::endl;
            std::cout<<"Money: "<<game.get_current_player()->check_balance()<<std::endl;
        }
        else if (game.get_current_player()->get_name() == "b")
        {
            std::cout<<"\033[32m" <<game.get_current_player()->get_name() << "'s turn:" << std::endl;
            std::cout<<"Money: "<<game.get_current_player()->check_balance()<<std::endl;

        }
        else if (game.get_current_player()->get_name() == "c")
        {
            std::cout<<"\033[36m" <<game.get_current_player()->get_name() << "'s turn:" << std::endl;
            std::cout<<"Money: "<<game.get_current_player()->check_balance()<<std::endl;
        }
        else if (game.get_current_player()->get_name() == "d")
        {
            std::cout<<"\033[35m" <<game.get_current_player()->get_name() << "'s turn:" << std::endl;
            std::cout<<"Money: "<<game.get_current_player()->check_balance()<<std::endl;
        }
        else{
            std::cout<<"\033[37m" <<game.get_current_player()->get_name() << "'s turn:" << std::endl;
            std::cout<<"Money: "<<game.get_current_player()->check_balance()<<std::endl;
        }


        if(game.get_current_player()->get_if_in_jail()==true)
        {
            game.get_current_player()->try_2_get_out_jail();
        }

        if(game.get_current_player()->get_if_in_jail() == false){
            std::cout<< "1 - Roll\n2 - Check Properties" << std::endl;
            std::cin >> menu_input;
            std::cout << "===================================" << std::endl;

            logic::Property* landed_property;
            std::cout << "===================================" << std::endl;
            std::cout << "You choose:" << std::stoi(menu_input) << std::endl;
            switch(std::stoi(menu_input)){
                case 1:
                    std::cout << "Rolling dice..." << std::endl;
                    game.dice.roll();
                    game.dice.get_dices();
                    if(game.dice.check_double()){
                        std::cout << "Double!" << std::endl;
                    }
                    
                    game.move_current_player(game.dice.get_total());
                        
                    landed_property = board.get_property(game.get_current_player()->get_position());
                    //game.get_current_player()->print_player();
                    landed_property->print_property();
                    
                    switch(landed_property->get_property_type()){
                        case FACULTY: case STATION: case UTILITY:
                            game.in_property(&board);
                            break;
                        
                        case CHANCE: 
                            std::cout << "You landed on Chance" << std::endl;
                            //choose random value for chance card
                            srand(time(NULL));
                            random_card = rand() % 16;
                            printf("%d", random_card);
                            board.chance_cards[random_card]->get_name();
                            board.chance_cards[random_card]->action(game.player_list, game.get_current_player());
                            // if the player lands on a chance card that makes him go to a property, allows player to buy it
                            if(random_card == 1 || random_card == 2 || random_card == 3 || random_card == 4 || random_card == 5 || random_card == 6 || random_card == 13){
                                game.in_property(&board);
                            }
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;

                        case COMMUNITY_CHEST:
                            std::cout << "You landed on Community Chest" << std::endl;
                            srand(time(NULL));
                            random_card = rand() % 16;
                            printf("%d", random_card);
                            board.community_chest_cards[random_card]->get_name();
                            board.community_chest_cards[random_card]->action(game.player_list, game.get_current_player());
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                        
                        case GO_TO_JAIL:
                            //std::cout << "Go immediately to praxis, caloiro " << std::endl;
                            std::cout << "PERDEU, PLAYBOY" << std::endl;
                            game.get_current_player()->set_position(10);   
                            game.get_current_player()->change_jail_status();
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                        case TAX:
                            std::cout << "You landed on Tax" << std::endl;
                            if(game.get_current_player()->get_position()==4){
                                std::cout << "You have to pay " <<  100 << std::endl;
                                game.get_current_player()->take_money(100);
                            }
                            else{
                                std::cout << "You have to pay " <<  200 << std::endl;
                                game.get_current_player()->take_money(200);
                            }
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                        case JAIL:
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                        case FREE_PARKING:
                            std::cout << "You landed on Free Parking" << std::endl;
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                        case GO:
                            std::cout << "You landed on Go" << std::endl;
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                        default:
                            std::cout << "You landed on " << landed_property->get_property_type() << std::endl;
                            if(!game.dice.check_double()){
                                game.check_bankrupt(&board);
                                game.next_player();
                            }
                            break;
                    }
                    break;
                case 2:
                    game.check_properties(&board);

                                    
                    break;
            }
        }  
        else
        {
            game.check_bankrupt(&board);
            game.next_player();
        }
    }
    
    for (int i = 0; i < game.number_players(); i++)
    {
        if(!game.player_list[i]->get_bankrupt())
            std::cout<< "Congratulations " << game.player_list[i]->get_name() << " for winning Unipoly Game\n  "<< std::endl;
    }
    

    game.delete_players();

    return 0;
}
    
    