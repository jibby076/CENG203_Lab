#pragma once
#include "../LinkedList/Node.h"     // reuse Week 3's Node: data + next

// Stack = LIFO (Last In, First Out).
// Every operation works at the top, which is the head of a linked list.
class Stack
{
private:
    Node* top;                      // nullptr = empty stack
    int   count;                    // number of elements

public:
    Stack();
    ~Stack();                       // delete every remaining node

    void push(int value);           // O(1): new node becomes the top
    bool pop(int& value);           // O(1): false = underflow (empty)
    bool peek(int& value) const;    // read the top, do not remove it
    bool isEmpty() const;
    int  size() const;
    void clear();                   // pop everything
    void display() const;           // top -> 8 5 7 2
};
