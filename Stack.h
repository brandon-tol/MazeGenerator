#pragma once
#include "Address.h"
#include <cstddef>

class Stack {
    struct Node {
        Address a;
        Node* next;
    };

    Node* head;

    public:
    Stack();
    Stack(Address);
    void push(Address);
    Address pop();
    bool isEmpty();
};