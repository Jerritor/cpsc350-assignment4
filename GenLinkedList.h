#pragma once
#include <iostream>
#include "GenNode.h"

using namespace std;

//====DECLARATION====
template <class T>
class NaiveList //Linked List class
{
  public:
    NaiveList();
    ~NaiveList();
    void insertFront(T data);
    void printList();

    const int peek() const;
    int removeFront();
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
NaiveList::NaiveList() //blank linkedlist
{
  size = 0;
  front = NULL;
}

template <class T>
NaiveList::~NaiveList()
{
  while (!isEmpty()) removeFront();
}

template <class T>
void NaiveList::insertFront(T data)
{
  ListNode *node = new ListNode; //create new node with data
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
void NaiveList::printList()
{
  ListNode *current = front;
  while (current) //this is a boolean check -- if not null
  {
    cout << current -> data << endl;
    current = current -> next;
  }
}

template <class T>
const T NaiveList::peek() const
{
  return front -> data;
}

template <class T>
T NaiveList::removeFront()
{
  int temp = front->data;	//temp = current/front node's data
  ListNode *old = front;	//save current node. (old->data should be saved?)

  front = front->next;		//change front pointer to next node

  old->next = NULL;		//set old.next pointer to nothing
  delete old;			//delete old, it's been allocated
  size--;			//decrease linkedlist size

  return temp;			//return front.data
}

template <class T>
int NaiveList::find(T value)
{
  int index = -1; //front is index = 0
  ListNode *current = front; //current = front node

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
int NaiveList::deletePosition(int position) //returns the deleted data
{
  //if position is within size boundaries and list exists
  if (position >= getSize() || position < 0 || isEmpty())
    return -1;
  if (position == 0) return removeFront();

  int index = 0; //prev's index is -1, current is 0

  //checks to make sure there's at least one node
  ListNode *previous = front; //previous node = front node
  ListNode *current = front; //current node = front node

  for(int i = 0; i < position; i++)
  {
    previous = current; //stay back?
    current = current->next; //current node = next node;
  }

  /**
  while (index != position)
  {
    previous = current; //stay back?
    current = current->next; //current node = next node;
    index++; //increment index
  }**/

  //when we find the correct position, update pointers

  previous->next = current->next;	//prev's next pointer point's at current's next pointer. skips current
  //if postion = 0, this means nothing

  current->next = NULL; //delete current.next pointer

  int temp = current->data; //save current data
  delete current; //delete current node
  size--; //decrease size by one
  return temp; //return the deleted node's data
}

template <class T>
bool NaiveList::isEmpty() const
{
  return front == NULL;
}

template <class T>
unsigned int NaiveList::getSize() const
{
  return size;
}
