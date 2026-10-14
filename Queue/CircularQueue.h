#pragma once

// Queue stored in a fixed-size array that wraps around:
// the slot after the last one is slot 0 again -> (index + 1) % CAPACITY
class CircularQueue
{
private:
    static const int CAPACITY = 5;
    int items[CAPACITY];
    int front;                      // index of the first element
    int count;                      // number of stored elements
    // rear = (front + count) % CAPACITY
public:
    CircularQueue();

    bool enqueue(int value);        // false = overflow (full)
    bool dequeue(int& value);       // false = underflow (empty)
    bool peek(int& value) const;
    bool isEmpty() const;
    bool isFull() const;
    int  size() const;
    void display() const;           // FIFO order + the raw array
};
