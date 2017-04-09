/*	Program Name: SmartCart
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_CHAR = 51;

int main()
{
	char newItem[MAX_CHAR];
	char prompt;
	double newItemPrice = 0;
	double cartSubtotal = 0;
	bool checkoutStatus = false;
	int counter = 0;
	int quantity = 0;

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);	

	cout << "\nWelcome to SmartCart!" << endl;
	while (!checkoutStatus)
	{
		cout << "What was the last item you put into your cart?" << endl;
		cin.get(newItem, MAX_CHAR, '\n');
		cin.ignore(MAX_CHAR, '\n');

		cout << "How many " << newItem << "(s) did you put into your cart?" << endl;
		cin >> quantity;
		counter = counter + quantity;
		cin.ignore(MAX_CHAR, '\n');

		cout << "How much do(es) each " << newItem << " cost?" << endl;
		cin >> newItemPrice;
		cin.ignore(MAX_CHAR, '\n');

		cartSubtotal = cartSubtotal + (quantity * newItemPrice);
		cout << "New SmartCart Subtotal: $" << cartSubtotal << endl;
		cout << "You currently have " << counter << " items in your cart. \nAre you ready to checkout? (y/n)" << endl;
		cin >> prompt;
		cin.ignore(MAX_CHAR, '\n');

		if (prompt == 'y' || prompt == 'Y')
			checkoutStatus = true;
	}
	cout << "*********************************************************************" << endl;
	cout << "\nYour Grand Total is: $" << cartSubtotal << " and you have " << counter << " items in your cart.\n" << endl;
	cout <<  "We have neither paper nor plastic bags, good luck!" << endl;
	return 0;
}
