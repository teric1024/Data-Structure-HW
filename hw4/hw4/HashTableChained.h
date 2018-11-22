/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

/**
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  HashTableChained.h
  version 1.0
*/

#ifndef HASHTABLECHAINED_H
#define HASHTABLECHAINED_H

#include "Dictionary.h"
#include "DoublyLinkedList/DList.h"
#include "DoublyLinkedList/DList.cpp"
#include "Entry.h"

template<typename K, typename V>
class HashTableChained : public Dictionary<K, V> {
private:

  /**
   *  Place any data fields here.
   **/
   int tablesize;
   int entrysize;
   DList<Entry<K,V>> *table;

public:

  /**
   *  Construct a new empty hash table intended to hold roughly sizeEstimate
   *  entries.  (The precise number of buckets is up to you, but we recommend
   *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
   **/
  HashTableChained(int sizeEstimate);

  /**
   *  Construct a new empty hash table with a default size.  Say, a prime in
   *  the neighborhood of 100.
   **/
  HashTableChained();

  /**
   *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
   *  to a value in the range 0...(size of hash table) - 1.
   *
   *  This function should be used by insert, find, and remove.
   **/
  int compFunction(int code);

  /**
   *  Returns the number of entries stored in the dictionary.  Entries with
   *  the same key (or even the same key and value) each still count as
   *  a separate entry.
   *  @return number of entries in the dictionary.
   **/
  virtual int size();

  /**
   *  Tests if the dictionary is empty.
   *
   *  @return true if the dictionary has no entries; false otherwise.
   **/
  virtual bool isEmpty();

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
  virtual void insert(const K& key, const V& value);//remove const

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
  virtual bool find(const K& key);

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
  virtual void remove(const K&  key);

  /**
   *  Remove all entries from the dictionary.
   */
  virtual void makeEmpty();

  /**
   *  check if n is prime.
   */
  bool is_Prime(int n);

  /**
   *  print all entries from the dictionary.
   */
  void print();

  /**
   *  count how many collisions we got.
   */
  int collision_count();
};
#endif
