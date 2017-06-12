#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int position = 8;
    int newInt = 100000000;

    int sum = sumOfList(head);
    cout << "Sum: " << sum << endl;

    cout << "List after insertion:" << endl;
    insert(head, position, newInt);

    display(head);
    destroy(head);
    
    return 0;
}
