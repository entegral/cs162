#include "list.h"

//put the implementation of your assigned functions here

void removeEven(node * &head)
{
    // removal from three positions: at head, middle, or at tail
    
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
        node *prior = NULL;
        int i = 0;
        while(i < position)
        {
            prior = current;
            current = current->next;
            i++;
            if (!current->next)
            {
                break;
            }
        }

        // check if toRemove is tail
        if (!current->next)
        {
            prior->next = NULL;
            delete current;
            current = NULL;
        }
        else 
        {
            prior->next = current->next;
            delete current;
            current = NULL;
        }
    }
}