#include "Tile.h"
#include <iostream>

void Tile::printLine1() {
    if(0b0010 & this->wall_data)
        std::cout << "XXX";
    else
        std::cout << "X X";
};

void Tile::printLine2() {
    if(0b1000 & this->wall_data)
        std::cout << "X ";
    else
        std::cout << "  ";
    if(0b0100 & this->wall_data)
        std::cout << "X";
    else
        std::cout << " ";
};

void Tile::printLine3() {
    if(0b0001 & this->wall_data)
        std::cout << "XXX";
    else
        std::cout << "X X";
};