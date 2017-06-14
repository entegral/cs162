#include "list.h"
using namespace std;

//put the implementation of your assigned functions here

void removeEven(node * &head)
{
	for (current = head; current; current = current->next)
	{
		next = current->next;

		//check to see if current pointer is head and even, if so remove and reassign head	
		if (current = head && current % 2 == 0)
		{
			head = head->next;
			delete current;
		}
		
		// check to see if next pointer is even, if so remove it and assign pointers
		else if (next->data % 2 == 0)
		{
			current->next = next->next;
			delete next;
		}
	}
}
	

int countEven(node * head)
{
	int count = 0;
	node * current = head;
	while (current)
	{
		if (current->data % 2 == 0)
		{
			count++;
		}
		current = current->next;
	}
	cout << "Number of evens: " << count << endl;
	return count;

}
