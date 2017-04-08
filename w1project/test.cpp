#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_CHAR = 101;

int main()
{
	char prompt[MAX_CHAR];

	cout << "Input something: ";
	cin.get(prompt, MAX_CHAR, '\n');
	cin.ignore(101, '\n');
	cout << "You said " << prompt << "!";
}
