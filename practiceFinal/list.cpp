#include "list.h"
using namespace std;

//put the implementation of your assigned functions here
int sumOfList(node * head)
{
	int total = 0;
	node * current;
	for (current = head; current; current = current->next)
	{
		total = total + current->data;
	}
	return total;
}

void insert(node* &head, int position, int newInt)
{
	node *newNode = new node;
	newNode->data = newInt;	

	// if insertion point is 0, insert as new head
	if (position == 0)
	{
		newNode->next = head;
		head = newNode;
	}

	// if insertion point is after the head, insert at proper index
	else 
	{
		int i = 0;
		node *current, *prior;
		for (current = head; current; current = current->next)
		{
			prior = current;
			i++;
			if (i >= position)
			{
				break;
			}
		}
		newNode->next = prior->next;
		prior->next = newNode;
		current = NULL;
		prior = NULL;
	}	
}

void removeByIndex(node * &head, int position)
{
	// removal from three positions: at head, middle, or at tail

	// count items in list
	int listSize = 0;
	node *counter = head;
	while (counter)
	{
		listSize++;
		counter = counter->next;
	}
	counter = NULL;
	// warn if index to remove is larger than list
	if (listSize < position + 1)
	{
		cout << "Index provided is larger than list. Try running again!" << endl;
		return;
	}

	// remove at head
	if (position == 0)
	{
		node *spare = head;
		head = head->next;
		delete spare;
		spare = NULL;
	}

	// remove at any other loation	
	else 
	{
		node *current = head;
		node *toRemove = NULL;
		node *prior = NULL;
		
		// point a pointer to the node to be removed
		int i = 0;
		while(i < position)
		{
			prior = current;
			current = current->next;
			i++;
		}
		toRemove = current;

		// check if toRemove is tail
		if (toRemove->next = NULL)
		{
			prior->next = NULL;
			delete toRemove;
			toRemove = NULL;
		}
		else
		{
			prior->next = toRemove->next;
			delete toRemove;
			toRemove = NULL;
		}
	}
}








