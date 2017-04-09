/* This program demonstrates how to read in integer and do error checking.

   Written by: Li Liang
   Date: 09/19/2009

   Sources: None
*/

#include <iostream>                 
#include <string>                   

using namespace std;                

int main ()
{
	int		age;

	//prompt user for input
	cout << "Please enter your age: ";
	cin >> age;

	//check if a valid integer is entered
	while (!cin)
	{
		//clear the error code for cin so that it can work again
		cin.clear();

		//throw away the garbage entered, e.g "None of your business."
		cin.ignore(100, '\n');

		//kindly ask again
		cout << "You've entered an illegal integer. Please try again: ";
		cin >> age;
	}

	//throw the rest of the line away, e.g. "99 Yippeeeeeee!"
	cin.ignore(100, '\n');

	//echo back the age
	cout << endl << age << " is cool!" << endl;
    
    return 0;
}


