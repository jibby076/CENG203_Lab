#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void DoublyLinkedList::insertAtFront(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head == nullptr)                // empty list: new node is tail too
        tail = newNode;
    else
        head->prev = newNode;           // old head points back to new node
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;               // O(1): no walk, tail is known

    if (tail == nullptr)                // empty list: new node is head too
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}

void DoublyLinkedList::displayForward() const
{
    cout << "Forward:  ";
    for (DNode* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

void DoublyLinkedList::displayBackward() const
{
    cout << "Backward: ";
    for (DNode* cur = tail; cur != nullptr; cur = cur->prev) // from tail
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

bool DoublyLinkedList::deleteValue(int value)
{
    DNode* cur = head;
    while (cur != nullptr && cur->data != value)
        cur = cur->next;
    if (cur == nullptr)                 // not found
        return false;

    if (cur->prev != nullptr)           // has a node before it ...
        cur->prev->next = cur->next;
    else
        head = cur->next;               // ... or it was the head

    if (cur->next != nullptr)           // has a node after it ...
        cur->next->prev = cur->prev;
    else
        tail = cur->prev;               // ... or it was the tail

    delete cur;
    return true;
}
