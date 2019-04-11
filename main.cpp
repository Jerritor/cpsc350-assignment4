#include <iostream>
#include "GenDoublyLinkedList.h"
using namespace std;

int main(int argc, char** argv)
{
	//GenLinkedList testList;
	GenDoublyLinkedList<int> dll;

	dll.insertFront(3);
	dll.insertBack(4);
	dll.insertFront(2);
	dll.insertBack(5);
	dll.insertFront(1);

	cout << "Printing List" << endl;
	dll.printList();

	cout << "Index of 2: " << dll.find(2) << endl;
	cout << "Removing Front: " << dll.removeFront() << endl;
	cout << "Peeking: " << dll.peek() << endl;
	cout << "Removing Back: " << dll.removeBack() << endl;

	cout << "Deleting Index 1...: " << dll.deletePosition(1) << endl;
	cout << "Peeking: " << dll.peek() << endl;

	cout << "Printing Remaining" << endl;
	dll.printList();

	return 0;
}
