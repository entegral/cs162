/*	Program Name: SmartCart
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Classroom Texts/Handouts
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_CHAR = 101;

int main()
{
	char newItem[MAX_CHAR];
	char prompt = '\0';
	double newItemPrice = 0;
	double cartSubtotal = 0;
	bool checkoutStatus = false;
	int counter = 0, quantity = 0;

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);	

	cout << "\nWelcome to SmartCart." << endl;
	while (!checkoutStatus)
	{
		//cout << "Please enter the name of the item you put into your cart:" << endl;
		//cin.get(newItem, MAX_CHAR, '\n');
		//cin.ignore(MAX_CHAR, '\n');

		//cout << "How many " << newItem << "(s) did you put into your cart?" << endl;
		//cin >> quantity;
		//cin.ignore(MAX_CHAR, '\n');
////
		//cout << "How much do(es) " << newItem << " cost?" << endl;
		//cin >> newItemPrice;
		//cin.ignore(MAX_CHAR, '\n');

		//cartSubtotal = cartSubtotal + (quantity * newItemPrice);
		//cout << "New SmartCart Subtotal: " << cartSubtotal << endl;
		//cout << "You have " << counter++ << "items in your cart. \nAre you ready to checkout? (y/n)" << endl;
		cin >> prompt;
		cin.ignore(MAX_CHAR, '\n');

		if (prompt == 'y' || 'Y')
			checkoutStatus = true;
	}
	cout << "Your Grand Total is: $" << cartSubtotal << " and you have " << counter << " item in your cart.\n" << endl;
	return 0;
}
