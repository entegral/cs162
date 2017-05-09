#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
	int newInt = 99;
	int position = 3;
    build(list, size);
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "Number of Even numbers: " << numOfEven(list, size) << endl;
    cout << "The list after insertion: " << endl;
    insert(list, size, newInt, position);

    display(list, size);
    
    return 0;
}
