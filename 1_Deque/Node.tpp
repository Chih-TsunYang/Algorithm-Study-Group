//
// Created by Chih-Tsun Yang on 8/12/23.
//
#ifndef INC_1_NODE_TPP
#define INC_1_NODE_TPP

#include "Node.h"

template<class T> Node<T>::Node()= default;

template<class T> Node<T>::Node(T e, Node *prev, Node *next) {
    this->elem = e;
    this->prev = prev;
    this->next = next;
}

template<class T> Node<T>::~Node()= default;

#endif //INC_1_NODE_TPP