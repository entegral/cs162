//This program does data validation
#include <iostream>
#include <string.h>
using namespace std;

//function prototypes
int readInt(char prompt[]);

int main()
{
    int num1 = 0, num2 = 0;
    char prompt[101];
    strcpy(prompt, "Please enter a whole number:");
    num1 = readInt(prompt);
    strcpy(prompt, "Please enter another whole number:");
    num2 = readInt(prompt);

    cout << "You entered: " << num1 << " and " << num2 << endl;

    return 0;
}

int readInt(char *prompt)
{
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while(!cin)
   {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Illegal input!! Please try again!!" << endl;
        cin >> temp;
   }
   return temp;
}


