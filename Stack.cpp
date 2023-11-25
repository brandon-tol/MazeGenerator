#include "Stack.h"
#include <stdexcept>

Stack::Stack(Address a) {
    this->head = new Node({a, nullptr});
};

Stack::Stack() : head(nullptr) { };

void Stack::push(Address a) {
    this->head = new Node({a, this->head});
};

Address Stack::pop() {
    if(this->head == nullptr) {
        throw std::runtime_error("Illegal attempt to pop from empty stack.");
    } else {
        Node* to_delete = head;
        head = head->next;
        Address a = to_delete->a;
        delete to_delete;
        return a;
    }
};

bool Stack::isEmpty() {
    return this->head == nullptr;
};