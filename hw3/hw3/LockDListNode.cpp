/**
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  LockDListNode.cpp
  version 1.0
*/

#include "LockDListNode.h"

template<typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n, bool l):DListNode<T>(i,p,n)
{
        isLocked = l;
}
