#pragma once
#include "Node.h"

class LinkedList
{
private:
    Node* head;                     // first node (nullptr = empty list)

public:
    LinkedList();
    ~LinkedList();

    // ---- Week 2 ----
    void insertAtFront(int value);
    void display() const;           // 7 -> 2 -> 5 -> 4 -> NULL
    bool isEmpty() const;

    // ---- Week 3 ----
    void insertAtEnd(int value);                    // Q2
    int  length() const;                            // Q2
    void createFromArray(const int arr[], int n);   // Q2
    int  search(int value) const;                   // Q3: index or -1
    int  update(int oldValue, int newValue);        // Q4: count changed
    bool insertAt(int index, int value);            // Q5: 0 = front
    bool deleteValue(int value);                    // Q6: first match only
    void merge(LinkedList& other);                  // Q7: empties other

    // ---- Week 5: recursion ----
    void displayBackward() const;   // 4 3 2 1 - via printBackward
    void reverse();                 // in place - via reverseFrom

private:
    static void  printBackward(const Node* node);   // recursive helper
    static Node* reverseFrom(Node* node);           // returns new head
};
