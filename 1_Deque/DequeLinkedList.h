//
// Created by Chih-Tsun Yang on 8/10/23.
//
#pragma once

#include "Deque.h"
#include "Node.h"


template<class T> class DequeLinkedList : public Deque<T>{
public:
public:
    DequeLinkedList();

    int getSize() override;

    void addFirst(T item) override;

    void addLast(T item) override;

    void printDeque() override;

    T removeFirst() override;

    T removeLast() override;

    T get(int index) override;

    ~DequeLinkedList();

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int size = 0;
};

#include "DequeLinkedList.tpp"