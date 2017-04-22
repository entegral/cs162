/*	Program Name: SmartCart
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/
#include "main.h"
#include "song.h"
#include "database.h"

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
				displayLibrary(songs,size);
				removeFromLibrary(songs, size);				// 	remove song by index: NOT SURE HOW TO DO THIS YET
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


bool quitProgram()
{
	cout << "Fine. Leave me, go. No, really its FINE!  (/°□°)/ ╯︵ ┻━┻  " << endl;
	return false;
}
