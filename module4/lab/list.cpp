#include "list.h"
#include <iostream>
using namespace std;

bool insert(int val, int intList[], int& size)
{
	//insert your code here and modify the following line
	int i;
	int j;
	if (size == 0) {
		intList[size++] = val;
	} else {
		for (i = 0; i < size; i++){
			if(val < intList[i]){
				break;					//	FUNCTIONAL
			}
		}
		for(j = size; j >= i; j--) {
			intList[j] = intList[j - 1];
		}
		intList[i++] = val;
		size++;
	}
	return true;
}

bool remove(int val, int intList[], int& size)
{
	//insert your code here and modify the following line
	return true;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



