#pragma once
#include "Direction.h"

struct Address {
    const unsigned x;
    const unsigned y;

    Address(unsigned, unsigned);
    Address(Address, Direction);
};