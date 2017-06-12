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


