/* This program demonstrates how to use loops and display floating point value.

   Written by: Li Liang
   Date: 09/20/2009

   Sources: None
*/

#include <iostream>                 
#include <string>    
#include <cctype>

using namespace std;                

int main ()
{
	float		mealCost;
	float		totalCost;
	float		tipRate;
	char		response;

	cout << endl << "Welcome to Smart Tipping Calculator!" << endl;

	//read in total meal cost
	cout << endl << "Please enter the total meal cost: (e.g. 12.98) ";
	cin >> mealCost;
	while(!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "Invalid Input! Please try again: ";
		cin >> mealCost;
	}
	cin.ignore (100, '\n');

	//allow user to try different tip rate to see the total cost
	do
	{
		//read in tip rate
		cout << endl << "Please enter the tip rate your prefer: (e.g. 0.18) ";
		cin >> tipRate;
		while(!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << "Invalid Input! Please try again: ";
			cin >> tipRate;
		}
		cin.ignore (100, '\n');

		//calculate total cost and display it
		totalCost = mealCost * (1 + tipRate);

		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << endl << "Total Cost: " << totalCost << endl;

		//update loop control variable "response"
		cout << endl << "Want to try a different rate? (Y/N) ";
		cin >> response;
		cin.ignore(100, '\n');
		response = tolower(response);
	} while ( response == 'y' );	//';' here!
	
	cout << endl << "Thank you for using Smart Tipping Calculator!" << endl;
    
    return 0;
}
