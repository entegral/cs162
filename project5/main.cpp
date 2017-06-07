/*	Program Name: Lyric Music Library
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/
#include "song.h"
#include "tools.h"

int main()
{
	cout << "Welcome to Lyric Music Library!" << endl;
	char menuSelection;
	bool loopControl = true;
	char fileName[MAXCHAR] = "songs.txt";

	SongList songs(fileName);

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
				songs.removeFromLibrary();				// DONE - song.cpp
				break;
			case 's':
			 	songs.searchForSongs();				// DONE - song.cpp
			 	break;										//
			case 'q':
				songs.writeData(fileName);				// DONE - database.cpp
				loopControl = false;				// DONE - main.cpp
				break;
			default:
				cout << "Invalid selection!" << endl;		//	menu input error handling
				break;
		}
	}
};
