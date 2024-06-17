#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Game.h"

class Server {
    public:
        void host_game();
        void join_game();
        void close_game();
    private:
        int game_id;
    
    };
