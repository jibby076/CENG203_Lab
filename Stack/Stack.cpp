#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top = nullptr;
    count = 0;
}

Stack::~Stack()
{
    clear();
}

void Stack::push(int value)
{
    Node* newNode = new Node;       // same four steps as insertAtFront
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    count++;
}

bool Stack::pop(int& value)
{
    if (top == nullptr)             // underflow: nothing to pop
        return false;
    Node* temp = top;
    value = top->data;              // give the value back to the caller
    top = top->next;
    delete temp;                    // free the node's memory
    count--;
    return true;
}

bool Stack::peek(int& value) const
{
    if (top == nullptr)
        return false;
    value = top->data;
    return true;
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}

int Stack::size() const
{
    return count;
}

void Stack::clear()
{
    int dummy;
    while (pop(dummy))              // pop until underflow
        ;
}

void Stack::display() const
{
    cout << "top ->";
    for (Node* cur = top; cur != nullptr; cur = cur->next)
        cout << " " << cur->data;
    if (top == nullptr)
        cout << " (empty)";
    cout << endl;
}
