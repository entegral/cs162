// songList.cpp
#include "songList.h"

// default constructor
SongList::songList()
{
    size = 0;
}

// constructor - read from file
SongList::songList(char fileName[])
{
    Song aSong;
    char tempTitle[MAXCHAR], tempArtist[MAXCHAR], tempAlbum[MAXCHAR];
    int tempMin, tempSec;
    ifstream inFile;

    inFile.open(fileName);
	if(!inFile)
	{
		cout << "File did not open, exiting program" << endl;
		exit(0);
	}

    // file opened, now load data to object
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
        aSong(tempTitle, tempArtist, tempMin, tempSec, tempAlbum);
		inFile.get(tempTitle, MAXCHAR, ';');
	}
	inFile.close();
}

// destructors
SongList::~songList()
{
    // nothing to do
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
	}
	cout << "*************************" << endl;
	return;
}

// function to add new song objects to the song array
// UPDATED FOR CLASSES
void SongList::addToLibrary()
{
	cout << "What is the title of the song you would like to add? " << endl;
	charArrayInput(char title[]);
	cout << "Who made this song? " << endl;
	charArrayInput(char artist[]);
	cout << "How many minuets is this song? (don't include seconds yet!) " << endl;
	int durationMin = intInput();
	cout << "How many seconds remain? " << endl;
	int durationSec = intInput();
	cout << "What is the name of the album? " << endl;
	charArrayInput(char album[]);
	Song aSong = song(title, artist, durationMin, durationSec, album);
	this->list[size++] = aSong;
	cout << aSong.title << " has been added to the library!" << endl;
	return;
}

// function to remove a song from a song array
void SongList::removeFromLibrary(Song songs[], int& size)
{
    int val;
	cout << "Enter the index of the song you would like to remove: " << endl;
	val = intInput();
    Song toRemove = songs[val];
	int j = 0;
    if (val) {
            for (j = val; j < size; j++) {
                    songs[j] = songs[j + 1];
            }
            size--;
    }
	cout << toRemove.title << " by " << toRemove.artist <<  " was removed from the library!" << endl;
	return;
}

// function to search for songs that might exist within the array
void SongList::searchForSongs(Song songs[], int &size)										// Search songs:
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
			if (strstr(songs[i].artist, searchQuery) != NULL)	{
				searchResults[searchSize++] = songs[i];
			}
		}
	} else if (searchOption == 'b')	{									// Search for songs by album
		cout << "What album would you like to search for?" << endl;					//	-changed strcmp to strstr so substrings could be caught by search
		charArrayInput(searchQuery);
		for (int i = 0; i < size; i++) {
			if (strstr(songs[i].album, searchQuery) != NULL) {
				searchResults[searchSize++] = songs[i];
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
void writeData(ofstream &outFile)
{
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
