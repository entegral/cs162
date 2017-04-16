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
void addToLibrary();
void removeFromLibrary();
void searchForSong();
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
				displayLibrary(songs, size);	// MAKE THIS FUNCTION: USE COUT TO PRINT SONGS[SIZE] DATA. INCLUDE INDEX OF SONG IN FORMATTING
				break;
			case 'a':
				addToLibrary();			// MAKE THIS FUNCTION: USE CIN TO RECEIVE INPUT FROM USER AND INPUT INTO NEW STRUCT INDEX OF SONGS[SIZE]
				break;
			case 'r':
				removeFromLibrary();		// remove song by index: NOT SURE HOW TO DO THIS YET
				break;
			case 's':
				searchForSong();		// Search for song by artist or album: NOT YET SURE HOW TO ONLY RETURN DESIRED SONG
				break;
			case 'q':
				loopControl = quitProgram();	// DONE
				break;
		}

	}


// d) search for song by:
// 		-artist
// 		-album


// e) quit

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
		cout << "Artist: " << songs[i].artist << endl;
		cout << "Duration: " << songs[i].durationMin << ":" << songs[i].durationSec << endl;
		cout << "Album: " << songs[i].album << endl;
		cout << endl;	
	}	
	cout << "*************************" << endl;
}

void addToLibrary()
{
	cout << "[PLACEHOLDER] added something to library" << endl;
}

void removeFromLibrary()
{
	cout << "[PLACEHOLDER] removed something from library" << endl;
}

void searchForSong()
{
	cout << "[PLACEHOLDER] searched library!" << endl;
}

bool quitProgram()
{
	cout << "[PLACEHOLDER] you quit!" << endl;
	return false;
}
