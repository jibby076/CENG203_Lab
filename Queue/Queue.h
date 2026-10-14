#pragma once
#include "../LinkedList/Node.h"     // same Node as the stack

// Queue = FIFO (First In, First Out).
// enqueue at the rear (last node), dequeue from the front (first node).
class Queue
{
private:
    Node* front;                    // first node: dequeue side
    Node* rear;                     // last node : enqueue side
    int   count;

public:
    Queue();
    ~Queue();

    void enqueue(int value);        // O(1) thanks to rear
    bool dequeue(int& value);       // O(1): false = underflow (empty)
    bool peek(int& value) const;    // the front element
    bool isEmpty() const;
    int  size() const;
    void display() const;           // front -> 2 7 5 8 <- rear
};
