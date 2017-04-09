/* This program demonstrates how to model string using c-string and 
   how to read in string with multiple words in it.
   
   Written by: Li Liang
   Date: 09/19/2009

   Sources: None
*/

#include <iostream>                 
#include <string>                   

using namespace std;  

const int MAX_CHAR = 101;

int main ()
{
    char	message[MAX_CHAR];		//a char array that can hold a message up to 100 characters
	char	reminder[MAX_CHAR];
	
	cout << endl << "Please enter the message for today: ";
	cin.get(message, MAX_CHAR, '\n');	
	cin.ignore(100, '\n');
	
	cout << endl << "Playing back the message for you: " << message << endl;   

	cout << endl << "Please enter reminder for tomorrow: ";
	cin.get(reminder, MAX_CHAR, '\n');	
	cin.ignore(100, '\n');
	
	cout << endl << "Reminder for tomorrow: " << reminder << endl;
    return 0;
}


