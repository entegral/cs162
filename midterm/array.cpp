//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

int sumOfEvens(int list[], int &size)
{
	int i;
	int count;
	for(i = 0; i < size; i++)
	{
		if(list[i] % 2 == 0)
		{
			count = list[i] + count;
		} 
	}
	cout << "Sum of evens: " << count << endl;
	return count;
}

void remove(int list[], int &size, int numOfInt)
{
	int i;
	for (i = 0; i <= size; i++)
	{
		list[i] = list[i + numOfInt];
	}
	size = size - numOfInt;
	cout << "List after removal: " << endl;
	return;
}
