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

struct Video
{
	char title[MAXCHAR];
	char genre[MAXCHAR];
	int qty;
	double rating;
};


// function prototypes
void printMenu();
void displayLibrary();
void addToLibrary();
void removeFromLibrary();
void searchByIndex();
bool quitProgram();

int main()
{

	char menuSelection;
	bool loopControl = true;

// Menu options:
	while(loopControl)
	{
		printMenu();
		cin >> menuSelection;
		cin.ignore(MAXCHAR, '\n');
		switch (menuSelection) {
			case 'd':
				displayLibrary();		// MAKE THIS FUNCTION
				break;
			case 'a':
				addToLibrary();			// MAKE THIS FUNCTION
				break;
			case 'r':
				removeFromLibrary();		// MAKE THIS FUNCTION
				break;
			case 's':
				searchByIndex();		// MAKE THIS FUNCTION
				break;
			case 'q':
				loopControl = quitProgram();					
				break;
		}

	}
// b) display information for all songs with index for each songs
//		-use array of "Songs" strut to model each song


// c) remove song by index


// d) search for song by:
// 		-artist
// 		-album


// e) quit

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

void displayLibrary()
{
	cout << "[PLACEHOLDER]displaying library!" << endl;
}

void addToLibrary()
{
	cout << "[PLACEHOLDER] added something to library" << endl;
}

void removeFromLibrary()
{
	cout << "[PLACEHOLDER] removed something from library" << endl;
}

void searchByIndex()
{
	cout << "[PLACEHOLDER] searched library!" << endl;
}

bool quitProgram()
{
	cout << "[PLACEHOLDER] you quit!" << endl;
	return false;
}
