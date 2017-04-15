#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int CAP = 100;
const int MAXCHAR = 101;

//function prototypes
void openFile(char [], ifstream &);
void initList(int [], int);
void readList(ifstream &, int [], int&);
void printList(const int [], const int);
int largest(const int [], const int);

int main()
{
    int list[CAP] = {0}, size = 0;
    char fileName[MAXCHAR];
    ifstream inFile;
    cout << "Please enter filename:";
    cin.get(fileName, MAXCHAR);
    strcpy(fileName, "numbers.txt");
    cin.ignore(100, '\n');
    openFile(fileName, inFile);
    //inits the list
    initList(list, CAP);
    readList(inFile, list, size);
    printList(list, size);
    cout << "Largest in your list is " << largest(list, size) << endl;
    inFile.close();
    return 0;
}

//open the file
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "File did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}
    
    
//init the array
void initList(int list[], int cap)
{
    for(int i = 0; i < cap; i++)
    {
        list[i] = -1;
    }
}

//reads numbers from the user    
void readList(ifstream &inFile, int list[], int &size)
{
    int temp = 0;
    while(inFile >> temp)
    {
        if(size == CAP)
        {
            cout << "Error!! List full!!" << endl;
            return;
        }
        //inFile  >> list[size++];
        list[size++] = temp;
    }
}

//prints the array
void printList(const int list[], const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

//finds the largest number in the list 
int largest(const int list[], const int size)
{
    ///insert code here
}








