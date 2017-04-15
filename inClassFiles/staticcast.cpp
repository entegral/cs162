//This program demos static cast
#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cout << "Please enter a number between 0 and 35:";
    cin >> num;
    char letter;
    //check if it is between 0 and 9
    if(num >= 0 && num <= 9)
    {
        letter = num;
        cout << "You entered: " << num << endl;
    }
    else if(num > 9 && num <= 35)
    {
        letter = static_cast<char>(num + 87);
        cout << "You entered: " << static_cast<char>(num + 87) << endl;
    }
    else
    {
        cout << "Illegal input!" << endl;
    }

    return 0;
}
