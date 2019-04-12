#include <iostream>
#include "GenDoublyLinkedList.h"
using namespace std;

void testDLL();

int main(int argc, char** argv)
{
	//testDLL();

	cout << "Program exited successfully." << endl;
	return 0;
}

void testDLL()
{
	//GenLinkedList testList;
	GenDoublyLinkedList<int> dll;

	dll.insertFront(3); //3
	dll.insertBack(4); //3 4
	dll.insertFront(2); //2 3 4
	dll.insertBack(5); //2 3 4 5
	dll.insertFront(1); //1 2 3 4 5

	cout << "Printing List" << endl;
	dll.printList(); //1 2 3 4 5

	cout << "Index of 2: " << dll.find(2) << endl; //3
	cout << "Removing Front: " << dll.removeFront() << endl; //r: 2 3 4 5
	cout << "Peeking: " << dll.peek() << endl; //2
	cout << "Removing Back: " << dll.removeBack() << endl; //r: 2 3 4

	cout << "Deleting Index 1...: " << dll.deletePosition(1) << endl; //r: 2 4
	cout << "Peeking: " << dll.peek() << endl; //2

	cout << "Printing Remaining" << endl; //2 4
	dll.printList();

	cout << "Emptying the queue..." << endl;
	while (!dll.isEmpty())
		cout << "Removing Front: " << dll.removeFront() << endl;
	cout << "Queue empty." << endl;
}
