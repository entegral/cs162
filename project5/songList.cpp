// songList.cpp
#include "songList.h"
#include "tools.h"
#include <cstring>

// default constructor
SongList::SongList()
{
    size = 0;
	Node newNode = new Node;
    newNode->data = new Song;
    newNode->next = NULL;
    newNode->prev = NULL;
    }
}

// constructor - read from file
SongList::SongList(char fileName[])
{
   	char tempTitle[MAXCHAR], tempArtist[MAXCHAR], tempAlbum[MAXCHAR], tempLineCount[MAXCHAR];
   	int tempMin, tempSec, lineCount;
    ifstream inFile;
	size = 0;
    head = NULL;
    tail = NULL;

    // open file using 'filename'
	inFile.open(fileName);
	if(!inFile)
	{
		cout << "File did not open, exiting program" << endl;
		exit(0);
	}

    // determine length of file to be read
    lineCount = 0;
    while (!inFile.eof())
        {
            inFile.getline(tempLineCount, MAXCHAR);
            lineCount++;
        }

    inFile.close();
    inFile.open(fileName);

    // file opened, now load data from file to object
	inFile.getline(tempTitle, MAXCHAR, ';');
	while(!inFile.eof())
	{
        // acquire song info in tmep variables
        inFile.getline(tempArtist, MAXCHAR, ';');
		inFile >> tempMin;
		inFile.ignore(100, ';');
		inFile >> tempSec;
		inFile.ignore(100, ';');
		inFile.getline(tempAlbum, MAXCHAR);

        // Allocate mem for newNode and set newNode's Song data
        Node *newNode = new Node;
        Node *current, *previous;
		newNode->data.setTitle(tempTitle);
		newNode->data.setArtist(tempArtist);
		newNode->data.setDurationMin(tempMin);
		newNode->data.setDurationSec(tempSec);
		newNode->data.setAlbum(tempAlbum);
        size++;
		inFile.getline(tempTitle, MAXCHAR, ';');

        // now add newNode to the existing (or not existing) linked List of songs at correct spot
        if (!head)
        {
            head = newNode;
            tail = newNode;                 // if head doesnt exist, assume list is not started and set newNode as single node in list
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else if (strcmp(newNode->data.getTitle(), head->data.getTitle()) < 0)
        {
            newNode->next = head;
            newNode->prev = NULL;           // if head does exist AND newNode's title < head's title, insert at beginning
            head->prev = newNode;
            head = newNode;
        }
        else if (strcmp(newNode->data.getTitle(), tail->data.getTitle()) > 0)
        {
            newNode->next = NULL;
            newNode->prev = previous;       // if newNode's title is bigger than tail's title, add it to the end of the list
            previous->next = newNode;
        }
        else
        {
            current = head;                                     // Lastly, if newNode does not belong at beginning, loop until correct spot then insert
            for (current; current; current = current->next)
            {
                if (strcmp(newNode->data.getTitle(), current->data.getTitle()) < 0)
                {
                    previous = current;                      // sets current to the spot that newNode should be inserted before
                    current = current->next;
                }
            }
            newNode->next = current;                            //  current and previous are set, now insert at location
            newNode->prev = current->prev;
            current->prev = newNode;
            previous->next = newNode;
        }
	}
	inFile.close();
}

// destructors
SongList::~SongList()
{
    // nothing to do
	if (list != NULL){
		delete [] list;
	}
}



// function to display all currently loaded song data
// UPDATED FOR CLASSES
void SongList::displayLibrary()
{
	cout << "**************************" << endl;
	cout << "****Collection Results****" << endl;
	cout << "**************************" << endl;
	for(int i = 0; i < size; i++)
	{
            list[i].printSongInfo();
            cout << "Index: " << i << endl;
	}
	cout << "*************************" << endl;
	return;
}

// overloaded display SongList function
void SongList::displayLibrary(Song result[], int size)
{
	cout << "**************************" << endl;
	cout << "****Collection Results****" << endl;
	cout << "**************************" << endl;
	for(int i = 0; i < size; i++)
	{
		result[i].printSongInfo();
	}
	cout << "*************************" << endl;
	return;
}


// function to add new song objects to the song array
// UPDATED FOR CLASSES
void SongList::addToLibrary()
{
    char tempTitle[MAXCHAR], tempArtist[MAXCHAR], tempDurationMin, tempDurationSec, tempAlbum[MAXCHAR];
    char *aTitle, *aArtist, *aAlbum;

	cout << "What is the title of the song you would like to add? " << endl;
	charArrayInput(tempTitle);
    aTitle = new char[strlen(tempTitle) + 1];
    strcpy(aTitle, tempTitle);
	cout << "Who made this song? " << endl;
	charArrayInput(tempArtist);
    aArtist = new char[strlen(tempArtist) + 1];
    strcpy(aArtist, tempArtist);
	cout << "How many minuets is this song? (don't include seconds yet!) " << endl;
	tempDurationMin = intInput();
	cout << "How many seconds remain? " << endl;
	tempDurationSec = intInput();
	cout << "What is the name of the album? " << endl;
	charArrayInput(tempAlbum);
    aAlbum = new char[strlen(tempAlbum) + 1];
    strcpy(aAlbum, tempAlbum);
	list[size].setTitle(aTitle);
    list[size].setArtist(aArtist);
    list[size].setDurationMin(tempDurationMin);
    list[size].setDurationSec(tempDurationSec);
    list[size++].setAlbum(aAlbum);
    list[size - 1].getTitle();
   	cout << " has been added to the library!" << endl;
	return;
}

// function to remove a song from a song array
void SongList::removeFromLibrary()
{
    int val;
	cout << "Enter the index of the song you would like to remove: " << endl;
	val = intInput();
    Song toRemove = list[val];
	int j = 0;
    if (val) {
            for (j = val; j < size; j++) {
                    list[j] = list[j + 1];
            }
            size--;
    }
    cout << toRemove.getTitle();
	cout << " by ";
    cout << toRemove.getArtist();
    cout <<  " was removed from the library!" << endl;
	return;
}

// function to search for songs that might exist within the array
void SongList::searchForSongs()										// Search songs:
 {
 	int searchOption;
 	char searchQuery[MAXCHAR] = {'\0'};
 	int searchSize = 0;
 	Song searchResults[CAP];

 	cout << "Would you like to (a) search by Artist, or (b) search by Album? " << endl;				// Search for songs by artist
 	searchOption = charInput();
 	if (searchOption == 'a') {
 		cout << "What artist would you like to search for?" << endl;
 		charArrayInput(searchQuery);
 		for (int i = 0; i < size; i++) {
 			if (list[i].compareArtist(searchQuery))	{
 				searchResults[searchSize++] = list[i];
 			}
 		}
 	} else if (searchOption == 'b')	{									// Search for songs by album
 		cout << "What album would you like to search for?" << endl;					//	-changed strcmp to strstr so substrings could be caught by search
 		charArrayInput(searchQuery);
 		for (int i = 0; i < size; i++) {
 			if (list[i].compareAlbum(searchQuery)) {
 				searchResults[searchSize++] = list[i];
 			}
 		}
 	} else {
 		cout << "You have entered an invalid option!\n" << endl;
 	}
 	if (searchSize == 0) {
 		cout << "There are no songs to display from your collection." << endl;
 	} else 	{
 		displayLibrary(searchResults, searchSize);
 	}
 	return;
 }

// writes data to file
// incorporated overloaded '<<' to allow for direct output of song objects
void SongList::writeData(char fileName[])
{
    ofstream outFile;
    outFile.open(fileName);
	if(!outFile)
	{
		cout << "outFile did not open, exiting program" << endl;
		exit(0);
	}

	for (int i = 0; i < size; i++){
		list[i].writeSong(outFile);
	}
	outFile.close();
	return;
}
