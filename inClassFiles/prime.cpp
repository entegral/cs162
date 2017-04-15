//This program checks to see if a number is prime or not
#include "tools.h"

//function prototype
bool isPrime(int);


//main
int main()
{
    int num = 0;
    char prompt[101];
    strcpy(prompt, "Please enter a whole number:");
    num = readInt(prompt);
    //call isPrime function
    if(isPrime(num))
    {
        cout << "Your number is prime!" << endl;
    }
    else
    {
        cout << "Your number is not prime!" << endl;
    }
    
    return 0;
}

//function to check if number is prime
bool isPrime(int num)
{
    if(num == 1)
        return false;
    else if(num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        for(int i = 3; i <= num/2; i+=2)
        {
            if(num % i == 0)
                 return false;
        }
        return true;
    }
} 
    
