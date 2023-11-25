#pragma once

struct Address {
    const unsigned x;
    const unsigned y;

    Address(unsigned, unsigned);
    Address(Address, unsigned char);
};