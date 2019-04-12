#pragma once
#include <iostream>
#include "GenDoublyLinkedList.h"
#include "RegistrarDeque.h"
#include "Student.h"

using namespace std;

GenDoublyLinkedList<Student> *dll;

RegistrarDeque::RegistrarDeque() { dll = new GenDoublyLinkedList<Student>(); }

RegistrarDeque::~RegistrarDeque() { delete dll; }

void RegistrarDeque::enqueue(Student s) { dll->insertBack(s); }

Student RegistrarDeque::dequeue() { return dll->removeFront(); }

const Student RegistrarDeque::front() { return dll->peek(); }

int RegistrarDeque::find(Student s) { return dll->find(s); }

int RegistrarDeque::getSize() { return dll->getSize(); }

bool RegistrarDeque::isEmpty() { return dll->isEmpty(); }

void RegistrarDeque::printQueue() { return dll->printList(); }

void RegistrarDeque::testDeque()
{
	Student one(1);
	Student two(2);
	Student three(3);
	Student four(4);
	Student five(5);

	enqueue(three); //3
	enqueue(four); //3 4
	enqueue(two); //3 4 2
	enqueue(five); //3 4 2 5
	enqueue(one); //3 4 2 5 1

	cout << "Printing List" << endl;
	printQueue(); //3 4 2 5 1

	cout << "Index of 2: " << find(two) << endl; //2
	cout << "Dequeing: " << dequeue() << endl; //r: 4 2 5 1
	cout << "Front of Queue: " << front() << endl; //4
	cout << "Dequeing: " << dequeue() << endl; //r: 2 5 1

	cout << "Printing List" << endl;
	printQueue(); //2 5 1

	cout << "Dequeing: " << dequeue() << endl; //r: 5 1
	cout << "Front of Queue: " << front() << endl; //5

	cout << "Printing Remaining" << endl; //5 1
	printQueue();

	cout << "Emptying the queue..." << endl;
	while (!isEmpty())
		cout << "Dequeing: " << dequeue() << endl;
	cout << "Queue empty." << endl;
}