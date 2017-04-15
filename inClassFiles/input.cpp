//This program does data validation
#include "tools.h"

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



