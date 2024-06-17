#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Property.h"
#include "Cards.h"

namespace logic {

    class Board {
        public:
            void create_board();
            void print_board();
            void check_properties(Player* player);
            
            std::vector<int> check_prop_improve(Player* player);
            bool check_if_can_build(Player* player, int id);
            std::vector<int> check_prop_mortgage(Player* player);
            std::vector<int> check_prop_unmortgage(Player* player);
            void mortgage_prop(Player* player, int id);
            void unmortgage_prop(Player* player, int id);
            Property* get_property(int position);
            Property* get_property_by_name(std::string name);
            //Property get_property(int position);
            std::vector<ChanceCard*> chance_cards; 
            std::vector<CommunityChestCard*> community_chest_cards;
            protected:
            std::vector<Property*> positions;

            };
            }
