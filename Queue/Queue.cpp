#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

Queue::~Queue()
{
    int dummy;
    while (dequeue(dummy))
        ;
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;        // it will be the last node

    if (rear == nullptr)            // empty queue: also the first node
        front = newNode;
    else
        rear->next = newNode;       // old last node points to the new one
    rear = newNode;
    count++;
}

bool Queue::dequeue(int& value)
{
    if (front == nullptr)           // underflow
        return false;
    Node* temp = front;
    value = front->data;
    front = front->next;
    if (front == nullptr)           // the queue became empty ...
        rear = nullptr;             // ... rear must not dangle
    delete temp;
    count--;
    return true;
}

bool Queue::peek(int& value) const
{
    if (front == nullptr)
        return false;
    value = front->data;
    return true;
}

bool Queue::isEmpty() const
{
    return front == nullptr;
}

int Queue::size() const
{
    return count;
}

void Queue::display() const
{
    cout << "front ->";
    for (Node* cur = front; cur != nullptr; cur = cur->next)
        cout << " " << cur->data;
    if (front == nullptr)
        cout << " (empty)";
    cout << " <- rear" << endl;
}
