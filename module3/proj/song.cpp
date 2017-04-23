// song.cpp
#include "song.h"


// function definitions
char charInput(char &input)
{
	char input[MAXCHAR];
	cin.getline(input, MAXCHAR);
	while(!cin)
	{
		cout << "Sorry you input an illegal value. Please try again: ";
		cin.getline(input, MAXCHAR);
	}
	return &input;
}

int intInput()
{
	int input;
	cin >> input;
	while(!cin)
	{
		cout << "Sorry you input an illegal value. Please try again: ";
		cin >> input;
	}
	cin.ignore(MAXCHAR, '\n');
	return input;
}


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
}

void addToLibrary(Song songs[], int &size)		// parameters needed: 	the array to add to AND the current size of it
{							// should pass the address of the original array and its size variable too
	Song newSong;
	cout << "What is the title of the song you would like to add? " << endl;
	cin.getline(newSong.title, MAXCHAR, '\n');
	cout << "Who made this song? " << endl;
	cin.getline(newSong.artist, MAXCHAR, '\n');
	cout << "How many minuets is this song? (don't include seconds yet!) " << endl;
	cin >> newSong.durationMin;
	cin.ignore(MAXCHAR, '\n');
	cout << "How many seconds remain? " << endl;
	cin >> newSong.durationSec;
	cin.ignore(MAXCHAR, '\n');
	cout << "What is the name of the album? " << endl;
	cin.getline(newSong.album, MAXCHAR, '\n');
	songs[size++] = newSong;
	cout << newSong.title << " has been added to the library!" << endl;
}

void removeFromLibrary(Song songs[], int& size)
{
        int val;
	cout << "Enter the index of the song you would like to remove: " << endl;
	cin >> val;
	cin.ignore(MAXCHAR,'\n');
        Song toRemove = songs[val];
	int j = 0;
        if (val) {
                for (j = val; j < size; j++) {
                        songs[j] = songs[j + 1];
                }
                size--;
        }
	cout << toRemove.title << " by " << toRemove.artist <<  " was removed from the library!" << endl;

}

void searchForSongs(Song songs[], int &size)										// Search songs:
{												//		- by artist first, if not present
	char searchOption;
	char searchQuery[MAXCHAR] = {'\0'};
	int searchSize = 0;
	Song searchResults[CAP];

	cout << "Would you like to search by (a) Artist, or (b) Album? " << endl;		// 	Search for songs by artist
	cin >> searchOption;
	cin.ignore(MAXCHAR, '\n');
	if (searchOption == 'a') {
		cout << "What artist would you like to search for?" << endl;
		cin.getline(searchQuery, MAXCHAR, '\n');
		for (int i = 0; i < size; i++) {
			if (strstr(songs[i].artist, searchQuery) != NULL)	{
				searchResults[searchSize++] = songs[i];
			}
		}
	} else if (searchOption == 'b')	{							// 	Search for songs by album
		cout << "What album would you like to search for?" << endl;			//	-changed strcmp to strstr so substrings could be caught by search
		cin.getline(searchQuery, MAXCHAR, '\n');
		for (int i = 0; i < size; i++) {
			if (strstr(songs[i].album, searchQuery) != NULL) {
				searchResults[searchSize++] = songs[i];
			}
		}
	} else {
		cout << "You have entered an invalid option!\n" << endl;			//	Check for invalid input, if invalid break from function
	}
	if (searchSize == 0) {
		cout << "There are no songs to display from your collection." << endl;
	} else 	{
		displayLibrary(searchResults, searchSize);
	}
}
