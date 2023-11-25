#include "Map.h"
#include "Stack.h"
#include "rng.h"
#include <iostream>

Map::Map(unsigned size) : Map(size, size) { };

Map::Map(unsigned len, unsigned ht) : len(len), ht(ht), map(new Tile[len * ht]) {
    for(unsigned i = 0; i < len; i++) {
        for(unsigned j = 0; j < ht; j++) {
            at({i, j})->wall_data = 0b1111;
        }
    }
    init();
};

Map::Map(unsigned size, bool) : len(size), ht(size), map(new Tile[len * ht]) {
    for(unsigned i = 0; i < len; i++) {
        for(unsigned j = 0; j < ht; j++) {
            at({i, j})->wall_data = 0b0000;
        }
    }
};

Tile* Map::at(Address a) {
    return &map[a.x + a.y*len];
};

void Map::visit(Address a) {
    if(!isEdge(a, LEFT)) at({a, LEFT})->wall_data |= 0b01000000;
    if(!isEdge(a, RIGHT)) at({a, RIGHT})->wall_data |= 0b10000000;
    if(!isEdge(a, DOWN)) at({a, DOWN})->wall_data |= 0b00100000;
    if(!isEdge(a, UP)) at({a, UP})->wall_data |= 0b00010000;
};

bool Map::visited(Address a, Direction d) {
    return at(a)->wall_data & ((unsigned char)0b10000000 >> (char)d);
};

bool Map::isEdge(Address a, Direction d) {
    switch(d) {
        case LEFT:
        return a.x == 0;
        case RIGHT:
        return a.x == len - 1;
        case UP:
        return a.y == ht - 1;
        case DOWN:
        return a.y == 0;
    }
    throw std::runtime_error("Illegal Direction Exception.");
};

void Map::removeWall(Address a, Direction d) {
    at(a)->wall_data &= ((signed char)0b11110111 >> (int)d);
    Address b = {a, d};
    at(b)->wall_data &= (((signed char)0b11110111 >> (int)d) ^ (((int)d <= RIGHT) ? 0b1100 : 0b11));
};

void Map::init() {
    Address initial = { (unsigned)rng::getRandomInt(0, len - 1), (unsigned)rng::getRandomInt(0, ht - 1) };
    visit(initial);
    Stack* stack = new Stack(initial);
    while(!stack->isEmpty()) {
        Address current = stack->pop();
        Direction hat[4];
        char hatsize = 0;
        if(!visited(current, LEFT) && !isEdge(current, LEFT)) hat[hatsize++] = LEFT;
        if(!visited(current, RIGHT) && !isEdge(current, RIGHT)) hat[hatsize++] = RIGHT;
        if(!visited(current, UP) && !isEdge(current, UP)) hat[hatsize++] = UP;
        if(!visited(current, DOWN) && !isEdge(current, DOWN)) hat[hatsize++] = DOWN;
        if(hatsize <= 0) continue;
        stack->push(current);
        Direction toVisit = hat[rng::getRandomInt(0, hatsize - 1)];
        removeWall(current, toVisit);
        Address neighbour = {current, toVisit};
        visit(neighbour);
        stack->push(neighbour);
    }
    delete stack;
};

void Map::print() {
    for(int i = ht - 1; i >= 0; i--) {
        for(unsigned j = 0; j < len; j++)
            at({j, i})->printLine1();
        std::cout << std::endl;
        for(unsigned j = 0; j < len; j++)
            at({j, i})->printLine2();
        std::cout << std::endl;
        for(unsigned j = 0; j < len; j++)
            at({j, i})->printLine3();
        std::cout << std::endl;
    }       
};