#include "Map.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Map *m = new Map(50, false);
    m->print();
    return 0;
}