#pragma once

#include "Player.h"
#include <string>

namespace logic {

    class ChanceCard {
        public:
            ChanceCard(std::string name, int type, std::string consequence);
            void action(std::vector<Player*> player_list, Player* curr_player);
            std::string get_name();
            int get_type();
            std::string get_consequence();
        private:
            std::string name;
            int type;
            std::string consequence;
    };

    class CommunityChestCard {
        public:
            CommunityChestCard(std::string name, int type, std::string consequence);
            void action(std::vector<Player*> player_list, Player* curr_player);
            std::string get_name();
            int get_type();
            std::string get_consequence();
        private:
            std::string name;
            int type;
            std::string consequence;
    }; 
} 
