//This is the implementation file for tools.h
#include "tools.h"

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

