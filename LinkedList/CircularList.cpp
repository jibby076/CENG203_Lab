#include "CircularList.h"
#include <iostream>
using namespace std;

CircularList::CircularList()
{
    head = nullptr;
}

CircularList::~CircularList()
{
    if (head == nullptr)
        return;
    Node* cur = head->next;
    while (cur != head) {               // delete every node except head
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete head;                        // ring is broken: delete the last
    head = nullptr;
}

void CircularList::append(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {              // first node points to itself
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* cur = head;
    while (cur->next != head)           // last node: its next is head
        cur = cur->next;
    cur->next = newNode;
    newNode->next = head;               // close the ring again
}

void CircularList::display() const
{
    if (head == nullptr) {
        cout << "(empty ring)" << endl;
        return;
    }
    Node* cur = head;
    do {                                // do-while: head is printed first
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);              // stop when we are back at head
    cout << "(back to " << head->data << ")" << endl;
}

int CircularList::length() const
{
    if (head == nullptr)
        return 0;
    int count = 0;
    Node* cur = head;
    do {
        count++;
        cur = cur->next;
    } while (cur != head);
    return count;
}
