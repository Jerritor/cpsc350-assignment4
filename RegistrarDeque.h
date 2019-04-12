#pragma once
#include <iostream>
#include "GenDoublyLinkedList.h"
#include "Student.h"

using namespace std;

class RegistrarDeque
{
  public:
	RegistrarDeque(); //base constructor
	~RegistrarDeque(); //base destructor

    void enqueue(Student s); //insertFront()
	Student dequeue(); //removeFront()
	const Student front(); //peek()
	int find(Student s); //find()
	int getSize(); //getSize()
	bool isEmpty(); //isEmpty()
	void printQueue(); //printList()

	void testDeque();
};