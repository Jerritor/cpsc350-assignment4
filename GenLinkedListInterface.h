#pragma once
#include <iostream>

template <class T>
class GenLinkedListInterface //Linked List base class
{
  public:
    virtual void insertFront(T data) = 0;
	virtual T removeFront() = 0;
	virtual int deletePosition(int position) = 0;

	virtual void printList() = 0;
    virtual const T peek() = 0;
    virtual int find(T data) = 0; //aka search(). returns index
    virtual bool isEmpty() const = 0;
    virtual int getSize() const = 0;

    //GenNode<T> *front;
	//GenNode<T> *back; (if doubly)
    //unsigned int size;
};
