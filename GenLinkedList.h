#pragma once
#include <iostream>
#include "GenNode.h"

using namespace std;

//====DECLARATION====
template <class T>
class GenLinkedList //Linked List base class
{
  public:
    GenLinkedList();
    ~GenLinkedList();
    virtual void insertFront(T data);
	virtual int removeFront();
	
	void printList();
    const int peek() const;
    int find(T data); //aka search(). returns index
    int deletePosition(int position);

    bool isEmpty() const;
    unsigned int getSize() const;

  private:
    GenNode *front;
    unsigned int size;
};

//====IMPLEMENTATION=========
template <class T>
GenLinkedList::GenLinkedList() //blank linkedlist
{
  size = 0;
  front = NULL;
}

template <class T>
GenLinkedList::~GenLinkedList()
{
  while (!isEmpty()) removeFront();
}

template <class T>
void GenLinkedList::insertFront(T data)
{
  GenNode *node = new GenNode; //create new node with data
  node -> data = data;
  if (size == 0)
    front = node;
  else
  {
    //node -> data = data; //setting node.data = data
    node -> next = front; //current node's next pointer (node.next) points to front node
    front = node;  //the new node is now the front node
  }
  size++; //increase size
}

template <class T>
void GenLinkedList::printList()
{
  GenNode *current = front;
  while (current) //this is a boolean check -- if not null
  {
    cout << current -> data << endl;
    current = current -> next;
  }
}

template <class T>
const T GenLinkedList::peek() const
{
  return front -> data;
}

template <class T>
T GenLinkedList::removeFront()
{
  int temp = front->data;	//temp = current/front node's data
  GenNode *old = front;	//save current node. (old->data should be saved?)

  front = front->next;		//change front pointer to next node

  old->next = NULL;		//set old.next pointer to nothing
  delete old;			//delete old, it's been allocated
  size--;			//decrease linkedlist size

  return temp;			//return front.data
}

template <class T>
int GenLinkedList::find(T value)
{
  int index = -1; //front is index = 0
  GenNode *current = front; //current = front node

  while(current != NULL) //if current == NULL, index = -1
  {
    ++index; //increase index
    if(current-> data == value) //if current.data = value
      break;
    else
      current = current->next;	//set current = next node
  }
  return index;
}

template <class T>
int GenLinkedList::deletePosition(int position) //returns the deleted data
{
  //if position is within size boundaries and list exists
  if (position >= getSize() || position < 0 || isEmpty())
    return -1;
  if (position == 0) return removeFront();

  int index = 0; //prev's index is -1, current is 0

  //checks to make sure there's at least one node
  GenNode *previous = front; //previous node = front node
  GenNode *current = front; //current node = front node

  for(int i = 0; i < position; i++)
  {
    previous = current; //stay back?
    current = current->next; //current node = next node;
  }

  previous->next = current->next;	//prev's next pointer point's at current's next pointer. skips current
  //if postion = 0, this means nothing

  current->next = NULL; //delete current.next pointer

  int temp = current->data; //save current data
  delete current; //delete current node
  size--; //decrease size by one
  return temp; //return the deleted node's data
}

template <class T>
bool GenLinkedList::isEmpty() const
{
  return front == NULL;
}

template <class T>
unsigned int GenLinkedList::getSize() const
{
  return size;
}
