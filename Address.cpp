#include "Address.h"

Address::Address(Address a, unsigned char d) : 
x(
    d >= 2 && d <= 4 ?
    a.x + 1 :
    d == 0 || d == 6 || d == 7 ?
    a.x - 1 :
    a.x
),
y(
    d >= 0 && d <= 2 ?
    a.y + 1 :
    d >= 4 && d <= 6 ?
    a.y - 1 :
    a.y
) { };
Address::Address(unsigned x, unsigned y) : x(x), y(y) { };