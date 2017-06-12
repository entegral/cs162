#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int position = 2;
    int newInt = 100000000;

    // sum list
    int sum = sumOfList(head);
    cout << "Sum: " << sum << endl;

    // insert into list
    cout << "List after insertion:" << endl;
    insert(head, position, newInt);
    display(head);

    // remove from list
    removeByIndex(head, position);
    display(head);
    destroy(head);
    
    return 0;
}
