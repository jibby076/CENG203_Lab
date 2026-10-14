#include "CircularQueue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue()
{
    front = 0;
    count = 0;
    for (int i = 0; i < CAPACITY; i++)
        items[i] = 0;               // so display() shows 0 in free slots
}

bool CircularQueue::enqueue(int value)
{
    if (isFull())
        return false;
    int rear = (front + count) % CAPACITY;  // first free slot, wraps to 0
    items[rear] = value;
    count++;
    return true;
}

bool CircularQueue::dequeue(int& value)
{
    if (isEmpty())
        return false;
    value = items[front];
    front = (front + 1) % CAPACITY;         // move front, wrap to 0
    count--;
    return true;
}

bool CircularQueue::peek(int& value) const
{
    if (isEmpty())
        return false;
    value = items[front];
    return true;
}

bool CircularQueue::isEmpty() const
{
    return count == 0;
}

bool CircularQueue::isFull() const
{
    return count == CAPACITY;
}

int CircularQueue::size() const
{
    return count;
}

void CircularQueue::display() const
{
    cout << "front ->";
    for (int i = 0; i < count; i++)
        cout << " " << items[(front + i) % CAPACITY];
    if (isEmpty())
        cout << " (empty)";
    cout << " <- rear   | array:";
    for (int i = 0; i < CAPACITY; i++)
        cout << " " << items[i];
    cout << "  front=" << front << " count=" << count << endl;
}
