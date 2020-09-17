//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"
#include "DoublyLinkedList.h"
template <typename T>
class DoublyLinkedList;
template <typename T>
class DoubleLinkedNode;
template<typename T>
class ConstDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
  friend DoublyLinkedList<T>;
  ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator& orig);

  ConstDoublyLinkedListIterator(const DoublyLinkedList<T>& list, const DoubleLinkedNode<T>* start);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ConstDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstDoublyLinkedListIterator<T> operator--(int); //post

  //get a const reference to the value
  const T& operator*() const;
 private:
  const DoublyLinkedList<T>& linkedList;
  const DoubleLinkedNode<T>* curNode;
};

template <typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator<T> &orig): linkedList(orig.linkedList), curNode(orig.curNode){}

template <typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const DoublyLinkedList<T> &list, const DoubleLinkedNode<T> *start): linkedList(list), curNode(start) {}

template <typename T>
bool ConstDoublyLinkedListIterator<T>::operator==(const ConstDoublyLinkedListIterator<T> &rhs) const {
  return ((rhs.curNode == curNode));
}

template <typename T>
bool ConstDoublyLinkedListIterator<T>::operator!=(const ConstDoublyLinkedListIterator<T> &rhs) const {
  return ((rhs.curNode != curNode));
}

template <typename T>
ConstDoublyLinkedListIterator<T>::operator bool() const{
  return (curNode != nullptr);
}

template <typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator++() {
  if(curNode) {
    curNode = curNode->next;
    return *this;
  } else {
    throw (std::overflow_error) "error lol";
  }

}

template <typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator++(int) {
  DoublyLinkedListIterator<T> cur(*this);
  curNode = curNode->next;
  return *cur;

}

template<typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator--() {
  if(curNode) {
    curNode = curNode->prev;
    return *this;
  } else{
    throw (std::underflow_error) "error lol";
  }
}

template<typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator--(int) {
  DoublyLinkedListIterator<T> cur(*this);
  curNode = curNode->prev;
  return cur;
}

template<typename T>
const T& ConstDoublyLinkedListIterator<T>::operator*() const {
  return curNode->data;
}

#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
