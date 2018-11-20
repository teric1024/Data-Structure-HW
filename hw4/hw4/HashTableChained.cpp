/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

/**
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  HashTableChained.cpp
  version 1.0
*/

#include "HashTableChained.h"
#include <iostream>
#include <typeinfo>
using namespace std;
//check if the input number is a prime
bool is_prime(int n)
{
    bool flag = true;
    for(int i = 2; i * i <= n; i += 1)
    {
        if(n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
    // Your solution here.
    int fprime = sizeEstimate;
    while(!is_prime(fprime))
    {
        fprime += 1;
    }
    tablesize = fprime;
    table = new DList<Entry<K,V>>[tablesize];
    entrysize = 0;
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
    // Your solution here.
    tablesize = 101;
    table = new DList<Entry<K,V>>[tablesize];
    entrysize = 0;
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
    // Replace the following line with your solution.
    int val = code % tablesize;
    return val;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size() {
    // Replace the following line with your solution.
    return entrysize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    // Replace the following line with your solution.
    if(entrysize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
    // Replace the following line with your solution.
    Entry<K,V> in(key,value);
    table[compFunction(key.hashCode())].insertFront(in);
    entrysize += 1;
    return;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) { //something wrong
    // Replace the following line with your solution.

    //"here" is a DList pointer pointing to the bucket where key may be.
    DList<Entry<K,V>> *here = &table[compFunction(key.hashCode())];
    //"current" points to the first entry of the bucket.
    DListNode<Entry<K,V>> *current = here->head->next;
    while (current != here->head) {
	if (typeid(key) == typeid(current->item->key))
        {
            if(key == current->item->key)
                return true;
        }
	else
	{
		current = current->next;
	}
    }
    return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key) { //something wrong
    // Replace the following line with your solution.

    //"here" is a DList pointer pointing to the bucket where key may be.
    DList<Entry<K,V>> *here = &table[compFunction(key.hashCode())];
    //"current" points to the first entry of the bucket.
    DListNode<Entry<K,V>> *current = here->head->next;
    while (current != here->head) {
	if (typeid(key) == typeid(current->item->key))
        {
            if(key == current->item->key)
            {
                here->remove(current);
                entrysize -= 1;
            }
        }
	else
	{
		current = current->next;
	}
    }
    return;
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
    // Your solution here.
    delete [] table;
    table = new DList<Entry<K,V>>[tablesize];
    entrysize = 0;
}
