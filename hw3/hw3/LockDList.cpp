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
    LockDListNode<T> *LLN = static_cast<LockDListNode<T>*>(node);
    LLN->isLocked = true;
    return;
}

//edit old function
template<typename T>
void LockDList<T>::remove(DListNode<T>* node)
{
    //error
    LockDListNode<T> *nnode = dynamic_cast<LockDListNode<T> *>(node);
    if(nnode->isLocked == true)
        return;
    else
    {
        DList<T>::remove(nnode);
        return;
    }
}

template<typename T>
LockDListNode<T>* LockDList<T>::newNode(const T& item,
		DListNode<T>* prev, DListNode<T>* next) {
	return new LockDListNode<T>(item, prev, next);
}

template<typename T>
DListNode<T>* LockDList<T>::front() {
	// Your solution here.
	return static_cast<LockDListNode<T>*>(DList<T>::front());
}

template<typename T>
DListNode<T>* LockDList<T>::back()
{
    return static_cast<LockDListNode<T>*>(DList<T>::back());
}

template<typename T>
DListNode<T>* LockDList<T>::next(DListNode<T>* node)
{
    return static_cast<LockDListNode<T>*>(DList<T>::next(node));
}

template<typename T>
DListNode<T>* LockDList<T>::prev(DListNode<T>* node)
{
    return static_cast<LockDListNode<T>*>(DList<T>::prev(node));
}
