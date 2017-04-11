#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int CAP = 100;
const char MAXCHAR = 101;

//function prototypes
void openFile(char [], ifstream &);
void initList(int [], int);
void readList(ifstream &, int [], int&);
void printList(int [], int);
void largest(int [], int);

int main(){

	int list[CAP] = {0}, size = 0;
	char filename[MAXCHAR];
	ifstream inFile;
	cout << "Please enter filename: ";
	cin.get(filename, MAXCHAR);
	cin.ignore(100, '\n');
	openFile(filename, inFile);
	//inits the list
	initList(list, CAP);
	//read list
	readList(inFile, list, size);
	// print list
	printList(list, size);
	cout << "largest in your list is " << largest
									// close file here
	return 0;
}

// open file
void openFile(char filename[], ifstream &inFile)
{
	inFile.open(filename);
	if(!inFile)
	{
		cout << "File did not open! Program Exiting!!!" << endl;
		exit(0);
	}
}

// to init the array
void initList(int list[], int cap)
{
	for(int i = 0; i < cap; i++)
	{
		list[i] = -1;
	}
}

// read the array
void readList(ifstream &inFile, int list[], int &size)
{
	while(!inFile.eof())
	{		
		if(size == CAP)
		{
			cout << "Error !! List full!!" << endl;
		}
		inFile >> list[size++];
	}
}

void printList(int list[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << list[i] << "\n";
	}
	cout << endl;
}

// finds largest number in array

int largest(const int list[], const int size)
{
		/// insert if statement and comparators here
}











