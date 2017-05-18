//This is the implementation file for tools.h
#include "tools.h"
#include "song.h"


//Function implementations
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
	cin.get(input);
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
