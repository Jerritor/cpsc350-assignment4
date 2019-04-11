#pragma once
#include <iostream>
#include "GenLinkedList.h"

//Uses DLLNode
template <class T>
class GenDoublyLinkedList : public GenLinkedList
{
  public:
    GenDoublyLinkedList();
    ~GenDoublyLinkedList();
    void insertFront(T data);
    void insertBack(T data); //queue insert()
    void printList();

    const T peek(); //queue front()/peek()
    T removeFront(); //queue remove()
    T removeBack();
    T find(T value); //aka search() - returns index
    int deletePosition(int position);
    DLLNode<T> *remove(int key); //key = value to find

    bool isEmpty() const; //queue isEmpty()
    unsigned int getSize() const; //queue size()

	//virtual functions
	//virtual
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

template <class T>
Node<T> DLLNode<T>::*getPrev() { return prev; }


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
void GenDoublyLinkedList<T>::printList()
{
  DLLNode<T> *current = front;
  while (current->next != NULL) //this is a boolean check
  {
	cout << (current->next != NULL) << " ";
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

template <class T>
T GenDoublyLinkedList<T>::find(T value)
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
DLLNode<T>* GenDoublyLinkedList<T>::remove(int key)
{
	DLLNode<T> *curr = front;
	while (curr->data != key)
	{
		curr = curr->next;
		if (!curr) return NULL;
	}
	if (curr == front)
		front = curr->next;
	else
		curr->prev->next = curr->next;
	if (curr == back)
        	back = curr->next;
	else
		curr->next->prev = curr->prev;

	curr->next = NULL;
	curr->prev = NULL;
	size--;
	return curr; //returns curr w/o prev & next pointers
	//curr doesn't actually get deallocated here
}

template <class T>
bool GenDoublyLinkedList<T>::isEmpty() const
{
  return front == NULL;
}

template <class T>
unsigned int GenDoublyLinkedList<T>::getSize() const
{
  return size;
}
