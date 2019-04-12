#include <iostream>
//#include "GenDoublyLinkedList.h"
//#include "RegistrarDeque.h"
//#include "FileIO.h"
#include "Simulation.h"
using namespace std;

//void testDLL();
//void testDeque();

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		cout << "=Assignment4 Initialized=" << endl;
		string textfile = argv[1];
		Simulation sim(textfile);
	}
	else
		cout << "Enter the file to be read as an argument." << endl;
	//testDeque();
	//testDLL();
	//FileIO io("readfile2.txt");

	cout << "Program exited successfully." << endl;
	return 0;
}

/**
void testDeque()
{
	RegistrarDeque dll;

	dll.enqueue(3); //3
	dll.enqueue(4); //3 4
	dll.enqueue(2); //3 4 2
	dll.enqueue(5); //3 4 2 5
	dll.enqueue(1); //3 4 2 5 1

	cout << "Printing List" << endl;
	dll.printQueue(); //3 4 2 5 1

	cout << "Dequeing: " << dll.dequeue() << endl; //r: 4 2 5 1
	cout << "Peeking: " << dll.peek() << endl; //4
	cout << "Dequeing: " << dll.dequeue() << endl; //r: 2 5 1

	cout << "Peeking: " << dll.peek() << endl; //2

	cout << "Printing Remaining" << endl; //2 5 1
	dll.printQueue();
	cout << "Dequeing: " << dll.dequeue() << endl; //r: 5 1

	cout << "Emptying the queue..." << endl;
	while (!dll.isEmpty())
		cout << "Removing Front: " << dll.dequeue() << endl;
	cout << "Queue empty." << endl;
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
**/
