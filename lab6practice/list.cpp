#include "list.h"

//put your implementation of LinkedList class here

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

bool LinkedList::add(int val)
{
	Node *newNode;
	newNode = new Node;

	newNode->data = val;		// fill new node with intended data

	if (!head)			// if no head exists yet, assume not list exits and assign head and tails to newNode
	{
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		tail = newNode;
	}
	else				// if head exists, assume a list is started and add the newNode to the list at the tail
	{
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

void LinkedList::printAscending() const
{
	Node *curr;
	curr = head;				// start for loop and iterate through using *curr 
	for (curr; curr; curr = curr->next)
	{
		cout << curr->data << " ";
	}
	cout << endl;
}

void LinkedList::printDescending() const
{
	Node *curr;
	curr = tail;				// start for loop and iterate through using *curr 
	for (curr; curr; curr = curr->prev)
	{
		cout << curr->data << " ";
	}
	cout << endl;
}

bool LinkedList::remove(int val)
{
	// determine if removal is at head, tail or in between and remove accordingly
	Node *current, *previous, *temp;
	current = head;
	previous = head;

	// removal if node is at the head
	if (head->data == val){
		temp = head;
		head = head->next;
		temp->next->prev = NULL;
		delete temp;
		return true;
	}
	// removal if node is at the tail
	else if(tail->data == val){
		temp = tail;
		temp->prev->next = NULL;
		tail = tail->prev;
		delete temp;
		return true;
	}
	// removal if node is neither at head or tail, iterate through list until current is ID'd, then set its pointers to NULL and connect the prior and post links
	else {
		while (current && current->data != val){
				previous = current;
				current = current->next;
		}
		previous->next = current->next;
		current->next->prev = previous;
		current->next = NULL;
		current->prev = NULL;
		delete current;
		return true;
	}
}
