#include "list.h"
using namespace std;

//put the implementation of your assigned functions here

void removeEven(node * &head)
{
	node * current, * prior, * next;
	current = head;
	while (current)
        {
		prior = current;
		current = current->next;
		next = current->next;

		// if at head
    		if (head->data % 2 == 0)
    		{
    		   	node *spare = head;
   				head = head->next;
   			    delete spare;
   			    spare = NULL;
   			    continue;
			}

			// if current is tail
			else if (current->data % 2 == 0 && !current->next)
			{
				prior->next = NULL;
				delete current;
				continue;
				}
			// if current is not tail
			else if (current->data % 2 ==0)
			{
				prior->next = current->next;
				delete current;
				current = prior;
				continue;
			}
			else
			{
				continue;
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
