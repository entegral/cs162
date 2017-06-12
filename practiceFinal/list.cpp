#include "list.h"

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

void remove(node * &head, int position)
{
	// removal from three positions: at head, middle, or at tail

	// count items in list
	int count = 0;
	node *counter = head;
	while (counter)
	{
		count++;
		counter = counter->next;
	}
	if (count - 1 > position)
	{
		std::cout << "Index position is larger than list. Try running again!" << std::endl;
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
		int i = 0;
		while(i < position)
		{
			prior = current;
			if (current->next)
			{
				current = current->next;
			}
			i++;
		}
		toRemove = prior->next;
		// check if toRemove is tail
		prior->next = toRemove->next;
		delete toRemove;
		toRemove = NULL;
		
	}
}








