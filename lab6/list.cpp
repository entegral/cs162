//put your implementation of LinkedList class here
#include "list.cpp"

LinkdedList::LinkedList()
{
	Node *newNode = new Node;
	newNode->data = '\0';
	newNode->next = NULL;
	newNode->prev = NULL;
	head = newNode;
	tail = newNode;
}

bool LinkedList::add(int val)
{
	Node *newNode = new Node;
	newNode->data = val;
	if (!head) {
		head = newNode;
		tail = newNode;
		next = NULL;
		prev = head;
		return true;
	}
	else {
		newNode->next = head;
		newNode->prev = &head;
		head = newNode;
		return true;
	}
}

void printAscending(){
	Node *curr;
	curr = head;
	for (curr, curr, curr = curr->next){
		cout << curr->data << endl;
	}
}

//bool LinkedList::remove(int val)
//{
//	Node *curr;
//	curr = head;
//	while(curr)
//	{
//		for (curr, curr != NULL, curr = curr->next){
//			
//		}
//	}
//}
