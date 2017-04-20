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
	char title[MAXCHAR] = {'\0'};
	char artist[MAXCHAR] = {'\0'};
	char album[MAXCHAR] = {'\0'};
	int durationMin;
	int durationSec;
};


// function prototypes
void printMenu();
void displayLibrary(Song[], int &);
void addToLibrary(Song[], int &);
void removeFromLibrary();
void searchForSongs(Song [], int &);
bool quitProgram();
void openFile(char [], ofstream &);
void writeData(const Song [], int &, ofstream &);
void openFile(char [], ifstream &);
void loadData(ifstream &, Song[], int &);

int main()
{

	char menuSelection;
	bool loopControl = true;
	char fileName[MAXCHAR] = "songs.txt";
	ifstream inFile;
	ofstream outFile;
	int size = 0;
	Song songs[CAP];
								// before all else, open file and load data
	openFile(fileName, inFile);
	loadData(inFile, songs, size);

								// Menu options:
	while(loopControl)
	{
		printMenu();
		cin >> menuSelection;
		cin.ignore(MAXCHAR, '\n');
		switch (menuSelection) 
		{
			case 'd':				
				displayLibrary(songs, size);			// DONE	MAKE THIS FUNCTION: USE COUT TO PRINT SONGS[SIZE] DATA. INCLUDE
				break;						// 	INDEX OF SONG FORMATTING
			case 'a':
				addToLibrary(songs, size);			// DONE	MAKE THIS FUNCTION: USE CIN TO RECEIVE INPUT FROM USER
				break;						//	AND INPUT INTO NEW STRUCT INDEX OF SONGS[SIZE]
			case 'r':
				removeFromLibrary();				// 	remove song by index: NOT SURE HOW TO DO THIS YET
				break;
			case 's':
				searchForSongs(songs, size);			// DONE	Search for song by artist or album
				break;						//	to only return desired song
			case 'q':
				openFile(fileName, outFile);
				writeData(songs, size, outFile);
				loopControl = quitProgram();			// DONE
				break;
			default:
				cout << "Invalid selection!" << endl;		//	menu input error handling
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

void openFile(char fileName[], ofstream &outFile)
{
	outFile.open(fileName);
	if(!outFile)
	{
		cout << "outFile did not open, exiting program" << endl;
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

void writeData(const Song songs[], int &size, ofstream &outFile)					//	function to write data out to file
{
	for (int i = 0; i < size; i++){
		outFile << songs[i].title << ";" << songs[i].artist << ";" << songs[i].durationMin << ";" << songs[i].durationSec << ";" << songs[i].album << endl;
	}
	outFile.close();
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

void removeFromLibrary()									// Remove song by index
{												//	- consider string compare to remove by name
	cout << "[PLACEHOLDER] removed something from library" << endl;
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

bool quitProgram()
{
	cout << "Fine. Leave me, go. No, really its FINE!  (/°□°)/ ╯︵ ┻━┻  " << endl;
	return false;
}
