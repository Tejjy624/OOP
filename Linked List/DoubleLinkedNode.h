//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

//the class that represents a node in the list
template<typename T>
class DoublyLinkedList;
template <typename T>
class DoublyLinkedListIterator;
template<typename T>
class ConstDoublyLinkedListIterator;
template <typename T>
class ReverseDoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;


template<typename T>
class DoubleLinkedNode {
 public:
  DoubleLinkedNode(T data, DoubleLinkedNode<T>* next, DoubleLinkedNode<T>* prev);
  friend DoublyLinkedList<T>;
  friend DoublyLinkedListIterator<T>;
  friend ConstDoublyLinkedListIterator<T>;
  friend ReverseDoublyLinkedListIterator<T>;
  friend ConstReverseDoublyLinkedListIterator<T>;
 private:
  T data;
  DoubleLinkedNode<T>* next = nullptr;
  DoubleLinkedNode<T>* prev = nullptr;
};
template <typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(T data, DoubleLinkedNode<T> *next, DoubleLinkedNode<T> *prev): data(data),
                                      next(next), prev(prev){}

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
