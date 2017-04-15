//This program demos char variables and char arrays
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char option;
    char name[101];
    cout << "Would you like to continue (y/n):";
    cin.get(option);
    cin.ignore(100, '\n');
    cout << "Please enter your name (100 characters or less):";
    cin.get(name, 101, '\n');
    getchar();
    cout << "You said " << option << " and your name is " << name << endl;

    return 0;
}
