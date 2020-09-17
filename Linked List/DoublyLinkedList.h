//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
  friend DoublyLinkedListIterator<T>;
  friend ConstDoublyLinkedListIterator<T>;
  friend ReverseDoublyLinkedListIterator<T>;
  friend ConstReverseDoublyLinkedListIterator<T>;
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator =  DoublyLinkedListIterator<T>;
  using const_iterator =  ConstDoublyLinkedListIterator<T>;
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>;
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);

  //create an empty DoublyLinkedList
  DoublyLinkedList();


  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();

  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
  void clearImpl(Node_Ptr node);
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

// Implemented members start here:

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
  len = 0;
}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values): DoublyLinkedList() {
  for (const auto& v: values) {
    push_back(v);
  }
  len = (int) values.size();
}

template <typename T>
void DoublyLinkedList<T>::clear() {
  clearImpl(head);
  head = nullptr;
  tail = nullptr;
  len = 0;
}

template<typename T>
void DoublyLinkedList<T>::clearImpl(Node_Ptr node) {
  if (node == nullptr) {
    return;
  } else {
    clearImpl(node->next);
    delete node;
  }
}

template <typename T>
T& DoublyLinkedList<T>::front() {
  return head->data;
}

template <typename T>
const T& DoublyLinkedList<T>::front() const {
  return head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back() {
  return tail->data;
}

template <typename T>
const T& DoublyLinkedList<T>::back() const {
  return tail->data;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T &value) {
  auto node = new DoubleLinkedNode<T>(value, nullptr, nullptr);

  if (len == 0) {
    head = node;
    tail = head;
} else {
    head->prev = node;
    node->next = head;
    head = node;
  }
  len++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
  auto node = new DoubleLinkedNode<T>(value, nullptr, nullptr);

  if (len == 0) {
    tail = node;
    head = tail;
  } else {
    tail->next = node;
    node->prev = tail;
    tail = node;
  }
  len++;
}

template <typename T>
bool DoublyLinkedList<T>::empty() const {
  return (len == 0);
}

template <typename T>
int DoublyLinkedList<T>::size() const {
  return len;
}

template <typename T>
void DoublyLinkedList<T>::insert(iterator &position, const T &value) {
  Node_Ptr temp = position.curNode;
  auto node = new DoubleLinkedNode<T>(value, nullptr, nullptr);
  if(len == 0) {
    head = node;
    tail = head;
    len++;
    return;
  }
  if(!temp->prev) {
    push_front(value);
    return;
  }

  node->next = temp;
  temp = temp->prev;
  node->prev = temp;
  temp->next = node;
  position.curNode->prev = node;
  len++;
}

template <typename T>
void DoublyLinkedList<T>::erase(iterator &position) {
  Node_Ptr temp = position.curNode;
  if(len == 0)
    return;
  if(len == 1) {
    head = nullptr;
    tail = nullptr;
    len--;
    return;
  }
  if (!temp->prev) {
    temp = temp->next;
    temp->prev = nullptr;
    head = temp;
  }
  else if (!temp->next) {
    temp = temp->prev;
    temp->next = nullptr;
    tail = temp;
  }
    else {
      temp = temp->prev;
      temp->next = position.curNode->next;
      temp = temp->next;
      temp->prev = position.curNode->prev;
      //delete (position.curNode);
    }

  len--;
}

// Iterator stuff starts here

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
  return DoublyLinkedListIterator<T>(*this, head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
  return DoublyLinkedListIterator<T>(*this, nullptr);
}


template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin()const {
  return ConstDoublyLinkedListIterator<T>(*this, head);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
  return ConstDoublyLinkedListIterator<T>(*this, nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin() {
  return ReverseDoublyLinkedListIterator<T>(*this, tail);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
  return ReverseDoublyLinkedListIterator<T>(*this, nullptr);
}
template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const {
  return typename DoublyLinkedList<T>::const_reverse_iterator(*this, tail);
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const {
  return typename DoublyLinkedList<T>::const_reverse_iterator(*this, nullptr);
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
