/*	Program Name: SmartCart
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

// constants
const int CAP = 100;
const int MAXCHAR = 101;

struct Song
{
	char title[MAXCHAR];
	char artist[MAXCHAR];
	char album[MAXCHAR];
	int durationMin;
	int durationSec;
};


// function prototypes
void printMenu();
void displayLibrary(Song[], int &);
void addToLibrary(Song[], int &);
void removeFromLibrary();
void searchByArtist(Song[], int&);
bool quitProgram();
void openFile(char [], ifstream &);
void loadData(ifstream &, Song[], int &);

int main()
{

	char menuSelection;
	bool loopControl = true;
	char fileName[MAXCHAR] = "songs.txt";
	ifstream inFile;
	int size = 0;
	Song songs[CAP];
	char searchOption;
								// before all else, open file and load data
	openFile(fileName, inFile);
	loadData(inFile, songs, size);

								// Menu options:
	while(loopControl)
	{
		printMenu();
		cin >> menuSelection;
		cin.ignore(MAXCHAR, '\n');
		switch (menuSelection) {
			case 'd':				
				displayLibrary(songs, size);	// 	MAKE THIS FUNCTION: USE COUT TO PRINT SONGS[SIZE] DATA. INCLUDE
				break;				// 	INDEX OF SONG FORMATTING
			case 'a':
				addToLibrary(songs, size);	// 	MAKE THIS FUNCTION: USE CIN TO RECEIVE INPUT FROM USER
				break;				//	AND INPUT INTO NEW STRUCT INDEX OF SONGS[SIZE]
			case 'r':
				removeFromLibrary();		// 	remove song by index: NOT SURE HOW TO DO THIS YET
				break;
			case 's':
				cout << "Would you like to search by (a) Artist, or (b) Album? " << endl;
				cin >> searchOption;
				cin.ignore(MAXCHAR, '\n');
				if (searchOption == 'a') {
					searchByArtist(songs, size);		// 	Search for song by artist or album
				} else if (searchOption == 'b') {
					cout << "album function not ready yet" << endl;
				} else {
				break;				//	to only return desired song
				}
			case 'q':
				loopControl = quitProgram();	// DONE
				break;
		}
	}
};

void openFile(char fileName[], ifstream &inFile)
{
	inFile.open(fileName);
	if(!inFile)
	{
		cout << "File did not open, exiting program" << endl;
		exit(0);
	}
}

void loadData(ifstream &inFile, Song songs[], int &size)
{
	inFile.get(songs[size].title, MAXCHAR, ';');
	while(inFile)
	{
		inFile.ignore(100, ';');
		inFile.get(songs[size].artist, MAXCHAR, ';');
		inFile.ignore(100, ';');
		inFile >> songs[size].durationMin;
		inFile.ignore(100, ';');
		inFile >> songs[size].durationSec;
		inFile.ignore(100, ';');
		inFile.getline(songs[size].album, MAXCHAR);
		size++;
		inFile.get(songs[size].title, MAXCHAR, ';');
	}
	inFile.close();
}

void printMenu()
{
	cout << "\nMusic Manager:" << endl;
	cout << "Choose from the foillowing menu options:" << endl;
	cout << "d) Display Music Library" << endl;
	cout << "a) Add to Music Library" << endl;
	cout << "r) Remove from Music Library" << endl;
	cout << "s) Search Music Library" << endl;
	cout << "q) Quit\n" << endl;
	cout << ": ";
}

void displayLibrary(Song songs[], int &size)
{
	cout << "*************************" << endl;
	cout << "*Current Song Collection*" << endl;
	cout << "*************************" << endl;
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

void removeFromLibrary()									// Remove song by index
{												//	- consider string compare to remove by name
	cout << "[PLACEHOLDER] removed something from library" << endl;
}

void searchByArtist(Song songs[], int &size)										// Search songs:
{												//		- by artist first, if not present
	char searchQuery[MAXCHAR];
	Song searchResults[CAP];
	int searchSize = 0;
	cout << "What artist would you like to search for?" << endl;
	cin.getline(searchQuery, MAXCHAR, '\n');
	cin.ignore(MAXCHAR, '\n');
	for (int i = 0; i < size; i++) 
	{
		if (songs[i].artist == searchQuery) 
		{
			searchResults[searchSize++] = songs[i];
		}
	}
	displayLibrary(searchResults, searchSize);
}

bool quitProgram()
{
	cout << "Fine. You can leave me, go. Really its FINE!  (╯°□°）╯︵ ┻━┻  " << endl;
	return false;
}
