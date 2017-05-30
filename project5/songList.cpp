// songList.cpp
#include "songList.h"
#include "tools.h"
#include <cstring>

// default constructor
SongList::SongList()
{
    size = 0;
    if (list)
    {
	delete [] list;
	list = NULL;
    }

}

// constructor - read from file
SongList::SongList(char fileName[])
{
   	int capacity = CAP;
	size = 0;
   	char tempTitle[MAXCHAR], tempArtist[MAXCHAR], tempAlbum[MAXCHAR], tempLineCount[MAXCHAR];
   	int tempMin, tempSec, lineCount;
    	ifstream inFile;

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
    list = new Song[lineCount * 2];	                              //  Dynamic list size allocation implementation
    inFile.close();
    inFile.open(fileName);

    // file opened, now load data from file to object
	inFile.getline(tempTitle, MAXCHAR, ';');
	while(!inFile.eof())
	{
		inFile.getline(tempArtist, MAXCHAR, ';');
		inFile >> tempMin;
		inFile.ignore(100, ';');
		inFile >> tempSec;
		inFile.ignore(100, ';');
		inFile.getline(tempAlbum, MAXCHAR);

        	// populate aSong
		list[size].setTitle(tempTitle);
		list[size].setArtist(tempArtist);
		list[size].setDurationMin(tempMin);
		list[size].setDurationSec(tempSec);
		list[size++].setAlbum(tempAlbum);
		inFile.getline(tempTitle, MAXCHAR, ';');
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
    toRemove.getTitle();
	cout << " by " << endl;
    toRemove.getArtist();
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
