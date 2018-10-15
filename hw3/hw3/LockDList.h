/**
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  LockDList.h
  version 1.0
*/

#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "LockDListNode.h"
#include "DList.h"

template<typename T>//flaw, with LockDListNode *head and DListNode *head
class LockDList: public DList<T>
{
public:
    //add new function
    LockDList();
    void lockNode(DListNode<T> *node);
    void remove(DListNode<T>* node);
    //override function
    virtual LockDListNode<T>* newNode(const T& item, DListNode<T>* prev,
			DListNode<T>* next);
};

#endif // LOCKDLIST_H

