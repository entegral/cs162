// song.cpp
#include "song.h"


// function definitions

// function for input and validation of character arrays
void charArrayInput(char input[])
{
	cin.getline(input, MAXCHAR);
	while(!cin)
	{
		cin.clear();
		cout << "Sorry you gave an illegal value. Please try again: ";
		cin.getline(input, MAXCHAR);
	}
	return;
}

// function for input and validation of chars
char charInput()
{
	char input;
	cin >> input;
	cin.ignore(MAXCHAR, '\n');
	while(!cin)
	{
		cin.clear();
		cout << "Sorry you gave an illegal value. Please try again: ";
		cin >> input;
		cin.ignore(MAXCHAR, '\n');
	}
	return input;
}

// function for input of intergers
int intInput()
{
	int input;
	cin >> input;
	while(!cin)
	{
		cin.clear();
		cin.ignore(MAXCHAR, '\n');
		cout << "Sorry you input an illegal value. Please try again: " << endl;
		cin >> input;
	}
	cin.ignore(MAXCHAR, '\n');
	return input;
}

// function to display all currently loaded song data
void displayLibrary(Song songs[], int &size)
{
	cout << "**************************" << endl;
	cout << "****Collection Results****" << endl;
	cout << "**************************" << endl;
	for(int i = 0; i < size; i++)
	{
		cout << "\nTitle: " << songs[i].title << endl;
		cout << "Index: :" << i << endl;
		cout << "Artist: " << songs[i].artist << endl;
		cout << "Duration: " << songs[i].durationMin << ":" << songs[i].durationSec << endl;
		cout << "Album: " << songs[i].album << endl;
		cout << endl;
	}
	cout << "*************************" << endl;
	return;
}

// function to add new song objects to the song array
void addToLibrary(Song songs[], int &size)							// parameters needed: 	the array to add to AND the current size of it
{												// should pass the address of the original array and its size variable too
	Song newSong;
	cout << "What is the title of the song you would like to add? " << endl;
	charArrayInput(newSong.title);
	cout << "Who made this song? " << endl;
	charArrayInput(newSong.artist);
	cout << "How many minuets is this song? (don't include seconds yet!) " << endl;
	newSong.durationMin = intInput();
	cout << "How many seconds remain? " << endl;
	newSong.durationSec = intInput();
	cout << "What is the name of the album? " << endl;
	charArrayInput(newSong.album);
	songs[size++] = newSong;
	cout << newSong.title << " has been added to the library!" << endl;
	return;
}

// function to remove a song from a song array
void removeFromLibrary(Song songs[], int& size)
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
void searchForSongs(Song songs[], int &size)										// Search songs:
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
