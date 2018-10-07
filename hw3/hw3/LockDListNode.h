/**
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  LockDListNode.h
  version 1.0
*/
#include "DListNode.h"

template<typename T>
class LockDList;

template<typename T>
class LockDListNode: public DListNode<T>
{
protected:
    friend class LockDList<T>;
    bool isLocked;
public:
    LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n, bool l):DListNode(i,p,n)
    {
        isLocked = l;
    }
}
