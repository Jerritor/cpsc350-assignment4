#pragma once
#include <iostream>

using namespace std;

class DequeNode
{
	public:
		DequeNode();
		DequeNode(int d);
		~DequeNode();

		int data;
		void incData(); //increase data by 1

		DequeNode *next;
		DequeNode *prev;
};

class RegistrarDeque
{
  public:
	RegistrarDeque(); //base constructor
	~RegistrarDeque(); //base destructor

    void enqueue(int w); //insertBack()
	int dequeue(); //removeFront() - returns wait time
	int peek(); //front() - front person's length of waiting

	int getSize(); //getSize()
	bool isEmpty(); //isEmpty()
	void printQueue(); //printList()

	void testDeque();
  private:
    DequeNode *front;
    DequeNode *back;
    unsigned int size;
};
