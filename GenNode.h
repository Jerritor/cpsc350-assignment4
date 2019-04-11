#pragma once
#include <iostream>

template <class T> //Template Class Declaration
class GenNode //Generic Node class
{
  public:
    GenNode();
    GenNode(T data);
    ~GenNode();
    T data; //data of this node
    GenNode<T> *next; //pointer to next node
};

//===Node Implementation===

template <class T>
GenNode<T>::GenNode()
{
  next = NULL;
}

template <class T>
GenNode<T>::GenNode(T d)
{
  data = d;
  next = NULL;
}

template <class T>
GenNode<T>::~GenNode() {} //nothing to deallocate?
