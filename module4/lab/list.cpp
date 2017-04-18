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
	int i = 0;
	int j = 0;
	bool temp = true;
	for (i = 0; i <= size; i++) {
		if (val == intList[i]) {				//	iterate through list, if value is found, do something. If not, return false
			temp = true;
			break;
		} else {
			temp = false;
		}
	}
	if (temp == true) {
		for (j = i; j < size; j++) {
			intList[j] = intList[j + 1];
		}
		size--;
	}
	return temp;
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



