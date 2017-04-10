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

int MAX_CHAR = 101

char charIoCheck();
int intIoCheck();

// Menu options:


// a) function to create new song and input information:
// 		- title
// 		- artist
// 		- duration
// 		- album


// b) display information for all songs with index for each songs
//		-use array of "Songs" strut to model each song


// c) remove song by index


// d) search for song by:
// 		-artist
// 		-album


// e) quit

char charIoCheck(input){
			while (!cin){
				cin.clear()
				cin.ignore(MAX_CHAR, '\n')
				cout << "Your entry was invalid, please try again:" << endl;
				cin.get(input, MAX_CHAR, '\n')
			}
			return input;
}

int intIoCheck(input){
			while (!cin){
				cin.clear()
				cin.ignore(MAX_CHAR, '\n')
				cout << "Your entry was invalid, please try again:" << endl;
				cin.get(input, MAX_CHAR, '\n')
			}
			return input;
}