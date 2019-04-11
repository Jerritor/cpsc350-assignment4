#pragma once
#include <iostream>
#include "GenLinkedListInterface.h"

using namespace std;

//====DLLNode DECLARATION====
template <class T>
class DLLNode
{
	public:
		DLLNode();
		DLLNode(T d);
		~DLLNode();

		T data;
		DLLNode<T> *next;
		DLLNode<T> *prev;
};


//====GenDoublyLinkedList DECLARATION====
template <class T>
class GenDoublyLinkedList : public GenLinkedListInterface<T>
{
  public:
    GenDoublyLinkedList();
    ~GenDoublyLinkedList();

	//overriding methods shared by ll & dll
    void insertFront(T data); //derived method
	T removeFront(); //derived method & queue remove()
	int deletePosition(int position);

	//overriding methods by linked list
	void printList();
    const T peek();
    int find(T data); //aka search(). returns index
    bool isEmpty() const;
    int getSize() const;

	//new dll methods
	void insertBack(T data); //queue insert()
	T removeBack();
  private:
    DLLNode<T> *front;
    DLLNode<T> *back;
    unsigned int size;
};


//===DLLNode IMPLEMENTATION===
template <class T>
DLLNode<T>::DLLNode()
{
  next = nullptr;;
  prev = nullptr;
}

template <class T>
DLLNode<T>::DLLNode(T d)
{
  data = d;
  next = nullptr;
  prev = nullptr;
}

template <class T>
DLLNode<T>::~DLLNode() {} //nothing to deallocate?


//===DLL IMPLEMENTATION===
template <class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList()
{
  size = 0;
  front = nullptr;
  back = nullptr;
}

template <class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList()
{
  while (!isEmpty()) removeFront();
}

template <class T>
void GenDoublyLinkedList<T>::insertFront(T data)
{
  DLLNode<T> *node = new DLLNode<T>(data); //create new node with data
  if (size == 0)
    back = node;
  else
  {
    front -> prev = node;
    node -> next = front; //current node's next node (node.next) points to front
  }
  front = node;  //the new node is now the front node
  size++; //increase size
}

template <class T>
T GenDoublyLinkedList<T>::removeFront()
{
  T temp = front->data;	//temp = current/front node's data
  DLLNode<T> *ft = front;		//save head

  front = front->next;		//change front to next node

  front-> prev = NULL;
  ft->prev = NULL;
  ft->next = NULL;		//set ft.next to not point to anything

  delete ft;			//delete ft, it's been allocated
  size--;			//decrease linkedlist size
  return temp;			//return front.data
}

template <class T>
int GenDoublyLinkedList<T>::deletePosition(int position) //assuming the list exists, returns the deleted data
{
  //invalid conditions
  if (position >= getSize() || position < 0 || isEmpty())
    return -1;

  if (position == 0)
    return removeFront();
  else if (position == getSize()-1)
    return removeBack();

  int index = 0;
  //checks to make sure there's at least one node
  DLLNode<T> *previous = front; //previous node = front node
  DLLNode<T> *current = front; //current node = front node

  //loops position-1 times. prev = remove.prev, curr = node to be removed
  for(int i = 0; i < position; i++)
  {
    previous = current; //stay back?
    current = current->next; //current node = next node;
  }

  //when we find the correct position, update pointers
  previous->next = current->next; //sets previous node's.next address to current.next
  current->next->prev = previous; //sets next.prev's node to previous

  current->next = NULL; //delete current.next pointer
  current->prev = NULL; //delete current.prev pointer
  T temp = current->data; //save current data

  delete current; //delete current
  size--; //decrease size by one
  return temp; //return the deleted node's data
}

template <class T>
void GenDoublyLinkedList<T>::printList()
{
  DLLNode<T> *current = front;
  while (current->next != NULL)
  {
	cout << (current->next != NULL) << " "; //adds a space between elems
    cout << current-> data << endl;
    current = current -> next;
  }
  cout << (current->next != NULL) << " ";
  cout << current-> data << endl;
}

template <class T>
const T GenDoublyLinkedList<T>::peek()
{
  return front -> data;
}

template <class T>
int GenDoublyLinkedList<T>::find(T value) //returns pos
{
  int index = -1;
  DLLNode<T> *current = front; //current = front node

  while(current != NULL)
  {
    ++index; //increase index
    if(current->data == value) //if current.data = value
      return index;
    else
      current = current->next;	//set current = next node
  }
  return -1;
}

template <class T>
bool GenDoublyLinkedList<T>::isEmpty() const
{
  return front == NULL;
}

template <class T>
int GenDoublyLinkedList<T>::getSize() const
{
  return size;
}

template <class T>
void GenDoublyLinkedList<T>::insertBack(T data)
{
  DLLNode<T> *node = new DLLNode<T>(data); //create new node with data
  if (size == 0)
  {
    front = node;
  }
  else
  {
    back -> next = node;
    node -> prev = back;
  }
  back = node;  //the new node is now the front node
  size++; //increase size
}



template <class T>
T GenDoublyLinkedList<T>::removeBack()
{
  T temp = back->data;
  DLLNode<T> *bk = back;

  back = back->prev;

  back->next = NULL;	//deallocating back.next
  bk->next = NULL;	//deallocating bk.next
  bk->prev = NULL;	//deallocating bk.prev

  delete bk;
  size--;
  return temp;
}
