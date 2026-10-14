#pragma once

// Stack stored in a fixed-size array: overflow is possible.
class ArrayStack
{
private:
    static const int CAPACITY = 5;  // maximum number of elements
    int items[CAPACITY];
    int topIndex;                   // index of the top element, -1 = empty

public:
    ArrayStack();                   // no destructor needed: no new

    bool push(int value);           // false = overflow (stack is full)
    bool pop(int& value);           // false = underflow (stack is empty)
    bool peek(int& value) const;
    bool isEmpty() const;
    bool isFull() const;
    int  size() const;
    void display() const;           // top -> 50 40 30 20 10
};
