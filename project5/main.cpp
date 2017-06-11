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
		menuSelection = charInput();				
		switch (menuSelection)						
		{
			case 'd':								
				songs.displayLibrary();				
				break;								
			case 'a':
				songs.addToLibrary();				
				 break;								
			case 'r':
				songs.displayLibrary();
				songs.removeFromLibrary();			
				break;								
			case 's':
			 	songs.searchForSongs();					
			 	break;									
			case 'q':
				songs.writeData(fileName);				
				return 0;								
			default:
				cout << "Invalid selection!" << endl;	
				break;
		}
	}
};
