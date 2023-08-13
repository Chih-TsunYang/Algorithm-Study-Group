//
// Created by Chih-Tsun Yang on 8/10/23.
//
#ifndef INC_1_DEQUE_DEQUELINKEDLIST_TPP
#define INC_1_DEQUE_DEQUELINKEDLIST_TPP

#include <iostream>
#include <iomanip>
#include "DequeLinkedList.h"
#include "Node.h"

template<class T> DequeLinkedList<T>::DequeLinkedList()= default;

template<class T> int DequeLinkedList<T>::getSize() {
    return this->size;
}

template<class T> void DequeLinkedList<T>::addFirst(T item) {
    Node<T> *newNode = new Node<T>(item, nullptr, this->head);
    if(size == 0){
        this->tail = newNode;
    } else {
        this->head->prev = newNode;
    }
    this->head = newNode;
    this->size++;
}

template<class T> void DequeLinkedList<T>::addLast(T item) {
    Node<T> *newNode = new Node<T>(item, this->tail, nullptr);
    if(size == 0){
        this->head = newNode;
    } else {
        this->tail->next = newNode;
    }
    this->tail = newNode;
    this->size++;
}

template<class T> void DequeLinkedList<T>::printDeque() {
    std::cout << "[ ";
    int cntPerLine = 0;
    Node<T> *ptr = this->head;
    while(ptr != nullptr){
        if (cntPerLine >= 8) {
            std::cout << std::endl << "  ";
            cntPerLine = 0;
        }
        cntPerLine++;
        std::cout << std::setw(8) << ptr->elem << "  ";
        ptr = ptr->next;
    }
    std::cout << " ]" << std::endl;
}

template<class T> T DequeLinkedList<T>::removeFirst() {
    if (this->size == 0){
        throw (std::length_error("[Error] Attempting to remove element from an empty queue!"));
    }
    Node<T> *secNode = this->head->next;

    T elem = this->head->elem;
    delete this->head;

    this->head = secNode;
    this->head->prev = nullptr;
    this->size--;

    return elem;
}

template<class T> T DequeLinkedList<T>::removeLast() {
    if (this->head == nullptr){
        throw (std::length_error("[Error] Attempting to remove element from an empty queue!"));
    }
    Node<T> *secLastNode = this->tail->prev;

    T elem = this->tail->elem;
    delete this->tail;

    this->tail = secLastNode;
    this->tail->next = nullptr;
    this->size--;

    return elem;
}

template<class T> T DequeLinkedList<T>::get(int index) {
    if(this->size == 0){
        throw(std::runtime_error("[Error] Attempting to get element from an empty queue!"));
    } else if(index >= this->size){
        throw(std::runtime_error("[Error] Attempting to access index out of bounds!"));
    }

    Node<T> *ptr = this->head;
    for(int i = 0; i < index; i++){
        ptr = ptr->next;
    }
    return ptr->elem;
}

template<class T> DequeLinkedList<T>::~DequeLinkedList() {
    Node<T> *ptr = this->tail;
    while(ptr->prev != nullptr){
        Node<T> *del = ptr;
        ptr = ptr->prev;
        delete del;
    }
}

#endif //INC_1_DEQUE_DEQUELINKEDLIST_TPP