// this program is similar to proj 2
// uses structs to maintain a video store
//struct object for video has titl, genre, quantity and rating
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//constants
const int CAP = 100;
const int MAXCHAR = 101;

struct Video
{
	char title[MAXCHAR];
	char genre[MAXCHAR];
	int qty;
	double rating;
};



int main()
{
	

	//create a variable for a single video
	Video store[CAP];
	cout << "please enter a title: ";
	cin.get(store[0].title, MAXCHAR);
	cin.ignore(100, '\n');
	cout << "Enter a genre: ";
	cin.get(store[0].genre, MAXCHAR);
	cin.ignore(100, '\n');
	cout << "enter quantity in store: ";
	cin >> store[0].qty;
	cout << "You entered: " << store[0].title << ";" << store[0].qty << endl;

	return 0;
}
