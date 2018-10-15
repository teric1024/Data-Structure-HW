/**
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  LockDList.cpp
  version 1.0
*/
#include "LockDList.h"
#include <iostream>
using namespace std;

//add new function
template<typename T>
LockDList<T>::LockDList()
{
    LockDListNode<T> *sentinel = NULL;
	sentinel = newNode(0, NULL, NULL);
	this->size = 0;
	this->head = sentinel;
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
}

template<typename T>//uncompleted
void LockDList<T>::lockNode(DListNode<T> *node)
{
    return;
}

//edit old function
template<typename T>
void LockDList<T>::remove(DListNode<T>* node)
{
    if(node->isLocked == true)
        return;
    else
    {
        DList<T>::remove(node);
        return;
    }
}

template<typename T>
LockDListNode<T>* LockDList<T>::newNode(const T& item,
		DListNode<T>* prev, DListNode<T>* next) {
	return new LockDListNode<T>(item, prev, next);
}
