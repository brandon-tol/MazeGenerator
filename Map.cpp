#include "Map.h"
#include "Stack.h"
#include "rng.h"
#include <iostream>
#define VISITED_0 (unsigned short)0b1000000000000000
#define WALL_0 (unsigned char)0b10000000

Map::Map(unsigned size) : Map(size, size) { };

Map::Map(unsigned len, unsigned ht) : len(len), ht(ht), map(new Tile[len * ht]) {
    for(unsigned i = 0; i < len; i++) {
        for(unsigned j = 0; j < ht; j++) {
            at({i, j})->wall_data = 0b11111111;
        }
    }
    init();
};

Tile* Map::at(Address a) {
    return &map[a.x + a.y*len];
};

void Map::visit(Address a) {
    for(unsigned char i = 0; i < 8; i++) {
        if(!isEdge(a, (Direction)i)) {
            at({a, (Direction)i})->wall_data |= (VISITED_0 >> i);
        }
    }
};

bool Map::visited(Address a, Direction d) {
    return at(a)->wall_data & (VISITED_0 >> (
        (d < 4) ?
        d + 4 :
        d - 4
    ));
};

bool Map::isEdge(Address a, Direction d) {
    switch(d) {
        case 0: return a.x == 0 || a.y == ht - 1;
        case 1: return a.y == ht - 1;
        case 2: return a.y == ht - 1 || a.x == len - 1;
        case 3: return a.x == len - 1;
        case 4: return a.x == len - 1 || a.y == 0;
        case 5: return a.y == 0;
        case 6: return a.y == 0 || a.x == 0;
        case 7: return a.x == 0;
    }
    return false;
};

void Map::removeWall(Address a, Direction d) {
    at(a)->wall_data &= (~(signed short)WALL_0 >> (unsigned char)d);
    Address b = {a, d};
    at(b)->wall_data &= ((~(signed short)WALL_0 >> (
        (d < 4) ?
        d + 4 :
        d - 4
    )));
};

void Map::init() {
    Address initial = { (unsigned)rng::getRandomInt(0, len - 1), (unsigned)rng::getRandomInt(0, ht - 1) };
    visit(initial);
    Stack* stack = new Stack(initial);
    while(!stack->isEmpty()) {
        Address current = stack->pop();
        Direction hat[8];
        char hatsize = 0;
        for(unsigned char i = 0; i < 8; i++) {
            if(!visited(current, (Direction)i) && !isEdge(current, (Direction)i)) hat[hatsize++] = (Direction)i;
        }
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
    for(unsigned i = ht - 1; i != -1; i--) {
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

#undef VISITED_0
#undef WALL_0