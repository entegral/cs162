//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

// numOfEven
int numOfEven(int list[], int &size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i] % 2 == 0)
			counter++;
		else
			continue;
	}
	return counter;
}


// insert
void insert(int list[], int &size, int newInt, int position)
{
	int j;
	for (j = size; j >= position; j--)
	{
		list[j] = list[j - 1];
	}
	list[j] = newInt;
	size++;
	cout << "The list after insertion: " << endl;
}
