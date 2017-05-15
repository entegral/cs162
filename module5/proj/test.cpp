// test.cpp
/*	Program Name: Lyric Music Library
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/
#include "test.h"
#include "song.h"

int main()
{

	Song bang =  Song::song();
	song.title = charArrayInput();
	song.artist = charArrayInput();
	song.durationMin = intInput();
	song.durationSec = intInput();
	song.album = charArrayInput();
	cout << "Your song info:" << endl;
	bang.printSongInfo();

	return 0;
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
          
