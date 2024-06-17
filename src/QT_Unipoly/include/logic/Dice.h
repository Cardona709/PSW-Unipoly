#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <string>

namespace logic{
     
class Dice {
    public:
        void roll();
        bool check_double();
        int get_total();
        int dices[2];
        void get_dices();
        
    };
}


