/*	Program Name: Lyric Music Library
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/
#include "song.h"


int main()
{

	char menuSelection;
	bool loopControl = true;
	char fileName[MAXCHAR] = "songs.txt";
	ifstream inFile;
	ofstream outFile;
	int size = 0;
	SongList songs;

// use database functions to load data
	openFile(fileName, inFile);
	loadData(inFile, songs, size);

// Menu - use loop and switch, each switch calls a function for the respective purpose
	while(loopControl)
	{
		printMenu();
		menuSelection = charInput();						// DONE - song.cpp
		switch (menuSelection)
		{
			case 'd':										// DONE - song.cpp
				songs.displayLibrary();				//
				break;										//
			case 'a':
				songs.addToLibrary();					// DONE - song.cpp
				 break;										//
			case 'r':
				songs.displayLibrary();
				SongList.removeFromLibrary(songs, size);				// DONE - song.cpp
				break;
			case 's':
				SongList.searchForSongs(songs, size);				// DONE - song.cpp
				break;										//
			case 'q':
				openFile(fileName, outFile);				// DONE - database.cpp
				writeData(songs, size, outFile);			// DONE - database.cpp
				loopControl = quitProgram();				// DONE - main.cpp
				break;
			default:
				cout << "Invalid selection!" << endl;		//	menu input error handling
				break;
		}
	}
};


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
	return;
}


bool quitProgram()
{
	cout << "Fine. Quit... No, really its FINE!  (/°□°)/ ╯︵ ┻━┻  " << endl;
	return false;
}

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
