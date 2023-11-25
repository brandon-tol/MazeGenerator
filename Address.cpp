#include "Address.h"

Address::Address(Address a, Direction d) : x((d == LEFT) ? (a.x - 1) : (d == RIGHT) ? (a.x + 1) : a.x), y((d == UP) ? (a.y + 1) : (d == DOWN) ? (a.y - 1) : a.y) { };
Address::Address(unsigned x, unsigned y) : x(x), y(y) { };