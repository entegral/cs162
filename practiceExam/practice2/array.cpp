//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

int numOfEven(int list[], int &size)
{
    int count = 0;
    int i;
    for (i = 0; i < size; i++)
	{
		if (list[i] % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

void insert(int list[], int &size, int newInt, int position)
{
	int i;
	for (i = size; i >= position; i--)
	{
		list[i] = list[i - 1];
		
	}
	list[i] = newInt;
	size++;
}

