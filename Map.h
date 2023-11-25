#pragma once
#include "Address.h"
#include "Tile.h"
#include "Direction.h"

class Map {
    Tile* map;
    unsigned len;
    unsigned ht;
    void init();
    void visit(Address);
    bool visited(Address, Direction);
    Tile* at(Address);
    bool isEdge(Address, Direction);
    void removeWall(Address, Direction);

    public:
    Map(unsigned, unsigned);
    Map(unsigned);
    void print();
};