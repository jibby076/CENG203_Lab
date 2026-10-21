#include "LinkedList.h"
#include <iostream>
using namespace std;

// =============================== Week 2 ===============================
LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while (head != nullptr) {           // delete the nodes one by one
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtFront(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::display() const
{
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "NULL" << endl;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

// =============================== Week 3 ===============================
void LinkedList::insertAtEnd(int value)                     // Q2
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {              // empty list: new node is the head
        head = newNode;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr)        // walk to the LAST node
        cur = cur->next;
    cur->next = newNode;
}

int LinkedList::length() const                              // Q2
{
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        count++;
    return count;
}

void LinkedList::createFromArray(const int arr[], int n)    // Q2
{
    for (int i = 0; i < n; i++)
        insertAtEnd(arr[i]);
}

int LinkedList::search(int value) const                     // Q3
{
    int index = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data == value)
            return index;               // found: stop at the FIRST match
        index++;
    }
    return -1;                          // visited every node, no match
}

int LinkedList::update(int oldValue, int newValue)          // Q4
{
    int changed = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data == oldValue) {
            cur->data = newValue;
            changed++;                  // no break: continue to the end
        }
    }
    return changed;
}

bool LinkedList::insertAt(int index, int value)             // Q5
{
    if (index < 0 || index > length())
        return false;                   // list unchanged
    if (index == 0) {
        insertAtFront(value);
        return true;
    }
    Node* prev = head;
    for (int i = 0; i < index - 1; i++) // stop at the node BEFORE the index
        prev = prev->next;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = prev->next;         // 1) new node points to the rest
    prev->next = newNode;               // 2) predecessor points to new node
    return true;
}

bool LinkedList::deleteValue(int value)                     // Q6
{
    if (head == nullptr)                // case 1: empty list
        return false;

    if (head->data == value) {          // case 2: the head node
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* prev = head;                  // case 3: middle or last node
    while (prev->next != nullptr && prev->next->data != value)
        prev = prev->next;

    if (prev->next == nullptr)          // case 4: not found
        return false;

    Node* temp = prev->next;
    prev->next = temp->next;            // unlink ...
    delete temp;                        // ... then free the memory
    return true;
}

void LinkedList::merge(LinkedList& other)                   // Q7
{
    if (other.head == nullptr)          // nothing to move
        return;
    if (head == nullptr) {
        head = other.head;
    }
    else {
        Node* cur = head;
        while (cur->next != nullptr)    // walk to the last node of THIS
            cur = cur->next;
        cur->next = other.head;
    }
    other.head = nullptr;               // other gives up its nodes
}

// =============================== Week 5 ===============================
void LinkedList::displayBackward() const
{
    printBackward(head);
    cout << endl;
}

void LinkedList::printBackward(const Node* node)
{
    if (node == nullptr)            // base case: past the last node
        return;
    printBackward(node->next);      // first go to the end ...
    cout << node->data << " ";      // ... print on the way back
}

void LinkedList::reverse()
{
    head = reverseFrom(head);
}

Node* LinkedList::reverseFrom(Node* node)
{
    if (node == nullptr || node->next == nullptr)
        return node;                // base case: last node = new head
    Node* newHead = reverseFrom(node->next);    // reverse the rest
    node->next->next = node;        // the next node now points back
    node->next = nullptr;           // old link removed (no cycle)
    return newHead;
}
