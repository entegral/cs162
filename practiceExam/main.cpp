#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);

    int newInt = 69;
    int position = 9;

    //PLEASE PUT YOUR CODE HERE to call the function assigned
     cout << "Number of evens in list: " << numOfEven(list, size) << endl;
    insert(list, size, newInt, position);

    display(list, size);
    
    return 0;
}
