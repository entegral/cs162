#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    countEven(head);
    removeEven(head);

    display(head);
    destroy(head);
    
    return 0;
}
