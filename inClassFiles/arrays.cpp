//This program demos arrays
#include <iostream>
using namespace std;

const int CAP = 10;

int main()
{
    int list[CAP] = {0};
    cout << "Please enter 5 numbers:";
    for(int i = 0; i < 5; i++)
    {
        cin >> list[i];
    }
    //output the whole array
    for(int i = 0; i < CAP; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl; 
    cout << list << endl;
    cin >> list;
    cout << endl;

    return 0;
}

