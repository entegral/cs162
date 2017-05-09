#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
	int numOfInt = 7; 
    build(list, size);
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    sumOfEvens(list, size);
    remove(list, size, numOfInt);

    display(list, size);
    
    return 0;
}
