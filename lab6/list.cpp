//put your implementation of LinkedList class here
#include "list.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

bool LinkedList::add(int val)
{
	Node *newNode = new Node;
	newNode->data = val;
	if (!head) {
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		return true;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = NULL;
		head = newNode;
		return true;
	}
}

void LinkedList::printAscending() const{
	Node *curr = new Node;
	cout << endl;
	for (curr = tail; curr; curr = curr->prev){
		cout << curr->data << " ";
	}
	cout << endl;
	delete curr;
}

void LinkedList::printDescending() const{
	Node *curr = new Node;
	cout << endl;
	for (curr = head; curr; curr = curr->next){
		cout << curr->data << " ";
	}
	cout << endl;
	delete curr;
}


bool LinkedList::remove(int val)
{
	Node *curr, *previous;
	previous = NULL;
	for (curr = head; curr; curr = curr->next){
		if (curr->data == val){
			curr->data = '\0';
			
			previous->next = curr->next;
			delete curr;
			delete previous;
			return true;
		}
		else {
			previous = curr;
		}	
	}
	delete curr;
	delete previous;
	return false;
}
