#include <iostream>
using namespace std;

int main()
{
	int ** table;
	int rows = 9, cols = 1;
	//write code here to allocate memory for the table

	// allocate memory for pointer array
	table = new int *[rows];

	// allocate memory for columns of table
	for (int i = 0; i < rows; i++)
	{
		table[i] = new int [cols++];
	}

	//write code here to populate it with required integers
	for (int j = 0; j < rows; j++)
	{
		for (int h = 0; h < j+1; h++)
		{
			table[j][h] = h;
		}
	}

	//write code here to print the table
	for (int j = 0; j < rows; j++)
	{
		for (int h = 0; h < j+1; h++)
		{
			cout << table[j][h] << " ";
		}
		cout << endl;
	}	

	//write code here to deallocate memory for the table
	for (int k = 0; k < rows; k++)
	{
		delete [] table[k];
	}
	delete table;
	
	return 0;
}

