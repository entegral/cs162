// songList.cpp
#include "songList.h"
#include "tools.h"
#include <cstring>

// default constructor
SongList::SongList()
{
    size = 0;
    head = NULL;
    tail = NULL;
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
		newNode->data.setTitle(tempTitle);
		newNode->data.setArtist(tempArtist);
		newNode->data.setDurationMin(tempMin);
		newNode->data.setDurationSec(tempSec);
		newNode->data.setAlbum(tempAlbum);
		inFile.getline(tempTitle, MAXCHAR, ';');

        // now add newNode to the existing (or not existing) linked List of songs at correct spot
        addNode(newNode);
	}
	inFile.close();
}

// destructors
SongList::~SongList()
{
    // need to iterate through linked list and set each pointer to NULL, then delete each Node
	if (head){
		Node *current = head;
        while (current)
        {
            current->prev = NULL;
            current->next = NULL;
            current = current->next;
        }
        delete head;
        delete tail;
        current = NULL;
        head = NULL;
        tail = NULL;
	}
}

void SongList::addNode(Node *newNode)
{
    char *nnString, *headString, *tailString;
    bool headStringActive = false;
    bool tailStringActive = false;
    nnString = new char [newNode->data.getTitleLen() + 1];
    newNode->data.getTitle(nnString);

    if (head){
        headString = new char [head->data.getTitleLen() + 1];
        head->data.getTitle(headString);
        headStringActive = true;
    }
    if (tail){
        tailString = new char [tail->data.getTitleLen() + 1];
        tail->data.getTitle(tailString);
        tailStringActive = true;
    }
    // if head doesnt exist, assume list is not started and set newNode as single node in list
    if (!head)
    {
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }

    // if head does exist AND newNode's title < head's title, insert at beginning
    else if (strcmp(nnString, headString) < 0)
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }

    // if newNode's title is bigger than tail's title, add it to the end of the list
    else if (strcmp(nnString, tailString) > 0)
    {
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Lastly, if newNode does not belong at beginning, loop until correct spot then insert
    else
    {
        Node *temp, *current, *previous;
        char *currString;
        previous = NULL;
        // this loop sets current so that newNode can be inserted before it
        for (temp = head; temp; temp = temp->next)
        {
            currString = new char[temp->data.getTitleLen() + 1];
            temp->data.getTitle(currString);
            if (strcmp(nnString, currString) < 0)
            {
                previous = temp->prev;
                current = temp;
                break;
            }
            delete [] currString;
            currString = NULL;
        }
        if (currString)
        {
            delete [] currString;
            currString = NULL;
        }

        //  current and previous are set, now insert at location
        newNode->next = current;
        newNode->prev = previous;
        current->prev = newNode;
        previous->next = newNode;
        temp = NULL;
        current = NULL;                     // NEVER AGAIN FORGET TO SET A POINTER TO NULL AFTER DELETING!
        previous = NULL;
    }
    if (headStringActive){
        delete [] headString;
        headString = NULL;
    }
    if (tailStringActive){
        delete [] tailString;
        tailString = NULL;
    }
    delete [] nnString;
    nnString = NULL;
    this->size++;
}

// function to display all currently loaded song data
// UPDATED FOR CLASSES
void SongList::displayLibrary()
{
	cout << "**************************" << endl;
	cout << "****Collection Results****" << endl;
	cout << "**************************" << endl;
    Node *current;
    int count = 0;
    for(current = head; current; current = current->next)
	{
		current->data.printSongInfo();
        cout << "Index: " << count++ << endl;
	}
	cout << "*************************" << endl;
    delete current;
	return;
}

//overloaded display SongList function
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

    Node *newNode = new Node;
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
	newNode->data.setTitle(aTitle);
    newNode->data.setArtist(aArtist);
    newNode->data.setDurationMin(tempDurationMin);
    newNode->data.setDurationSec(tempDurationSec);
    newNode->data.setAlbum(aAlbum);

    // check if song is already in library
    Node *checker;

    for (checker = head; checker; checker = checker->next)
    {
        if (checker->data.compareTitle(aTitle))
        {
            cout << "You already have this song in your Library!" << endl;
            delete newNode;
            newNode = NULL;
            checker = NULL;
            return;
        }
    }

    addNode(newNode);

    delete checker;
    checker = NULL;

    delete [] aTitle;
    delete [] aArtist;
    delete [] aAlbum;

    cout << aTitle << " has been added to the library!" << endl;
    newNode = NULL;

	return;
}

// function to remove a song from a song array
void SongList::removeFromLibrary()
{
    Node *toRemove, *ahead, *prior;
    toRemove = head;
    ahead = NULL, prior = NULL;
    int val, i;
	cout << "Enter the index of the song you would like to remove: " << endl;
	val = intInput();

    // if value is zero, then remove head
    if (val == 0)
    {
        ahead = head->next;
        ahead->prev = NULL;
        head = ahead;
    }
    // if value = size - 1, then remove tail
    else if (val == this->size - 1)
    {
        toRemove = tail;
        prior = tail->prev;
        prior->next = NULL;
        tail = prior;
    }
    // any other value given, iterate through list and remove respective node
    else
    {
        for (i = 0; i < val; i++)
        {
            toRemove = toRemove->next;
            ahead = toRemove->next;
            prior = toRemove->prev;
        }
        prior->next = toRemove->next;
        ahead->prev = toRemove->prev;
        toRemove->next = NULL;
        toRemove->prev = NULL;
    }

    this->size--;
    toRemove->data.printSongInfo();
    cout << " was removed from the library!" << endl;

    delete toRemove;
    toRemove = NULL;
    ahead = NULL;
    prior = NULL;

	return;
}

// function to search for songs that might exist within the array
void SongList::searchForSongs()										// Search songs:
 {
 	int searchOption;
 	char searchQuery[MAXCHAR] = {'\0'};
 	int searchSize = 0;
 	Song searchResults[CAP];
    Node *current;

 	cout << "Would you like to (a) search by Artist, or (b) search by Album? " << endl;				// Search for songs by artist
 	searchOption = charInput();
 	if (searchOption == 'a') {
 		cout << "What artist would you like to search for?" << endl;
 		charArrayInput(searchQuery);

        for (current = head; current; current = current->next)
        {
 			if (current->data.compareArtist(searchQuery))	{
 				searchResults[searchSize++] = current->data;
 			}
 		}

 	} else if (searchOption == 'b')	{									// Search for songs by album
 		cout << "What album would you like to search for?" << endl;					//	-changed strcmp to strstr so substrings could be caught by search
 		charArrayInput(searchQuery);

        for (current = head; current; current = current->next)
        {
 			if (current->data.compareAlbum(searchQuery)) {
 				searchResults[searchSize++] = current->data;
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
    Node *current;
    ofstream outFile;
    outFile.open(fileName);
	if(!outFile)
	{
		cout << "outFile did not open, exiting program" << endl;
		exit(0);
	}

	for (current = head; current; current = current->next){
		current->data.writeSong(outFile);
	}
	outFile.close();
    delete current;
    current = NULL;
	return;
}
