#pragma once
#include <iostream>

template <class T> //Template Class Declaration
class GenNode //Generic Node class
{
  public:
    ListNode();
    ListNode(T data);
    ~ListNode();
    T data; //data of this node
    ListNode *next; //pointer to next node
};

//===Node Implementation===

template <class T>
inline ListNode::ListNode()
{
  next = NULL;
}


inline ListNode::ListNode(T d)
{
  data = d;
  next = NULL;
}

inline ListNode::~ListNode() {} //nothing to deallocate?
