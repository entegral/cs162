//This program is similar to project2
//Uses structs to maintain a VideoStore
//Struct object for video has title, genre, quantity, and rating
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//constants
const int CAP = 100;
const int MAXCHAR = 101;

struct Video
{
    char title[MAXCHAR];
    char genre[MAXCHAR];
    int qty;
    double rating;
};

//function prototypes
void openFile(char [], ifstream &);
void loadData(ifstream &, Video [], int &);
void showList(const Video [], const int);

//main
int main()
{
    //create a variable for a single video
    Video store[CAP];
    char fileName[MAXCHAR] = "videos.txt";
    ifstream inFile;
    int size = 0;
    openFile(fileName, inFile);
    loadData(inFile, store, size);
    showList(store, size);
    return 0;
}

void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "File did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}
   
     
void loadData(ifstream &inFile, Video store[], int &size)
{
    inFile.get(store[size].title, MAXCHAR, ';');
    while(inFile)
    {
        inFile.ignore(100, ';');
        inFile.get(store[size].genre, MAXCHAR, ';');
        inFile.ignore(100, ';');
        inFile >> store[size].qty;
        inFile.ignore(100, ';');
        inFile >> store[size].rating;
        inFile.ignore(100, '\n');
        size++;
        inFile.get(store[size].title, MAXCHAR, ';');
    }
    inFile.close();
}

//This function prints the list of videos
    
void showList(const Video store[], const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << store[i].title << ";" << store[i].genre << ";" << store[i].qty << ";" << store[i].rating << endl;
    }
}     




















