#pragma once
#include "Address.h"
#include "Tile.h"

class Map {
    Tile* map;
    unsigned len;
    unsigned ht;
    bool withDiagonals;
    void init();
    void visit(Address);
    bool visited(Address, unsigned char);
    Tile* at(Address);
    bool isEdge(Address, unsigned char);
    void removeWall(Address, unsigned char);

    public:
    Map(unsigned, unsigned, bool = true);
    Map(unsigned, bool = true);
    void print();
};