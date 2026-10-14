#pragma once        // added by Visual Studio - keep it! (see Q5)

// One element of a singly linked list
struct Node
{
    int   data;     // the value stored in this node
    Node* next;     // next node's address (nullptr = end of list)
};
