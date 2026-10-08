#include "LinkedList.h" // 1) your own header first

#include <iostream> // 2) then what THIS file needs

using namespace std;


LinkedList::LinkedList() // LinkedList:: = member of LinkedList

{

	head = nullptr;

}
LinkedList::~LinkedList()

{

	while (head != nullptr) { // delete the nodes one by one

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
// Fill in these bodies question by question. The stubs compile and link,
// so the whole project builds from the start.

void LinkedList::insertAtEnd(int value)                     // Q2
{
	// TODO
}

int LinkedList::length() const                              // Q2
{
	return 0;                                               // TODO
}

void LinkedList::createFromArray(const int arr[], int n)    // Q2
{
	// TODO: call insertAtEnd() for every element
}

int LinkedList::search(int value) const                     // Q3
{
	return -1;                                              // TODO
}

int LinkedList::update(int oldValue, int newValue)          // Q4
{
	return 0;                                               // TODO
}

bool LinkedList::insertAt(int index, int value)             // Q5
{
	return false;                                           // TODO

}

bool LinkedList::deleteValue(int value)                     // Q6
{
	return false;                                           // TODO
}

void LinkedList::merge(LinkedList& other)                   // Q7
{
	// TODO
}

