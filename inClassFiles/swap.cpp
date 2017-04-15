//This program demos reference parameters
#include <iostream>
using namespace std;

//function prototypes
void swap(int &, int &);
int main()
{
    int x = 0, y = 0;
    cout << "Please enter 2 numbers and I will swap them:";
    cin >> x;
    cin >> y;
    cout << "Numbers before calling the swap function: " << x << " and " << y << endl;
    //swap function
    swap(x, y);
    cout << "Numbers after calling the swap function: " << x << " and " << y << endl;
    return 0;
}

//swap function
void swap(int &x, int &y)
{
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}
