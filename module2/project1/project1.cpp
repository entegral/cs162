/*	Program Name: SmartCart
	Developed by: Robert Bruce
	Citations: 	1) C++ Programming: From Problem Analysis to Program Design
			2) Class Texts/Handouts
*/

#include <iostream>
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

	// Welcome customer to SmartCart and enter while loop
	cout << "\nWelcome to SmartCart!" << endl;
	while (!checkoutStatus) {
		// Input/ask for item name
		cout << "What was the last item you put into your cart?" << endl;
		cin.get(newItem, MAX_CHAR, '\n');
		while (!cin) {
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			cout << "You entered an illegal value. Please try again: ";
			cin.get(newItem, MAX_CHAR, '\n');
		}
		cin.ignore(MAX_CHAR, '\n');

		// Input/ask for quantity of item
		cout << "How many " << newItem << "(s) did you put into your cart?" << endl;
		cin >> quantity;
		while (!cin) {
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			cout << "You entered an illegal value. Please try again: ";
			cin >> quantity;
		}
		counter = counter + quantity;
		cin.ignore(MAX_CHAR, '\n');

		// Input/ask for unit-cost of each item
		cout << "How much do(es) each " << newItem << " cost?" << endl;
		cin >> newItemPrice;
		while (!cin) {
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			cout << "You entered an illegal value. Please try again: ";
			cin >> newItemPrice;
		}
		cin.ignore(MAX_CHAR, '\n');

		// calculate new SmartCart subtotal
		cartSubtotal = cartSubtotal + (quantity * newItemPrice);
		cout << "New SmartCart Subtotal: $" << cartSubtotal << endl;
		
		// Check to see if customer is ready for checkout / exit loop
		cout << "You currently have " << counter << " items in your cart. \nAre you ready to checkout? (y/n)" << endl;
		cin >> prompt;
		while (!cin) {
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			cout << "You entered an illegal value. Please try again: ";
			cin >> prompt;
		}
		cin.ignore(MAX_CHAR, '\n');

		if (prompt == 'y' || prompt == 'Y')
			checkoutStatus = true;
	}
	
	// Provide checkout information in appropriate formatting
	cout << "***************************************************************" << endl;
	cout << "\nYour Grand Total is: $" << cartSubtotal << " and you have " << counter << " items in your cart.\n" << endl;
	cout <<  "We provide neither paper nor plastic bags, \ngood luck carrying your groceries!!" << endl;
	cout << "\n***************************************************************" << endl;
	return 0;
}
