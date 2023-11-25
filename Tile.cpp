#include "Tile.h"
#include <iostream>

void Tile::printLine1() {
    if(!!(0b10000000 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
    if(!!(0b01000000 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
    if(!!(0b00100000 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
};

void Tile::printLine2() {
    if(!!(0b00000001 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
    std::cout << " ";
    if(!!(0b00010000 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
};

void Tile::printLine3() {
    if(!!(0b00000010 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
    if(!!(0b00000100 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
    if(!!(0b00001000 & this->wall_data))
        std::cout << "X";
    else
        std::cout << " ";
};