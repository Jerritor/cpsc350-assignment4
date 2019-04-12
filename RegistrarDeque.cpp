#pragma once
#include <iostream>
#include "RegistrarDeque.h"

using namespace std;

DequeNode::DequeNode()
{
	next = nullptr;
	prev = nullptr;
}

DequeNode::~DequeNode() { }

/////////////

RegistrarDeque::RegistrarDeque()
{
	size = 0;
	front = nullptr;
	back = nullptr;
}

RegistrarDeque::~RegistrarDeque()
{
	while (!isEmpty()) dequeue();
}

void RegistrarDeque::enqueue(int w) //insertback()
{
	DequeNode *node = new DequeNode(w); //create new node with data
    if (size == 0)
      front = node;
    else
    {
      back -> next = node;
      node -> prev = back;
    }
    back = node;  //the new node is now the front node
    size++; //increase size
	node->waittime++; //set waittime to 0
}

int RegistrarDeque::dequeue()
{
	int temp = front->waittime;	//temp = current/front node's data
    DequeNode *ft = front;		//save head

    if (getSize() > 1)
    {
  	  front = front->next;		//change front to next node
  	  front->prev = NULL;
    }
    else front = NULL;

    ft->prev = NULL;
    ft->next = NULL;		//set ft.next to not point to anything

    delete ft;			//delete ft, it's been allocated
    size--;			//decrease linkedlist size
    return temp;			//return front.data
}

int RegistrarDeque::peek()
{
	return front->waittime;
}

int RegistrarDeque::getSize()
{
	return size;
}

bool RegistrarDeque::isEmpty()
{
	return front == NULL;
}

void RegistrarDeque::printQueue()
{
	DequeNode *current = front;
    while (current->next != NULL)
    {
  	//cout << (current->next != NULL) << " "; //returns if current.next exists
      cout << current-> waittime << endl;
      current = current -> next;
    }
    //cout << (current->next != NULL) << " ";
    cout << current-> waittime << endl;
}
