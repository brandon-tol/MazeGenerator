#include "Map.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Map *m = new Map(100);
    m->print();
    // std::cout << (Direction)(unsigned char)11;
    return 0;
}