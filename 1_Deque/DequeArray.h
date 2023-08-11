//
// Created by Chih-Tsun Yang on 7/30/23.
//
#pragma once

#include "Deque.h"

template<class T> class DequeArray : public Deque<T> {
public:

    explicit DequeArray(int capacity = 10);

    int getSize() override;

    void addFirst(T item) override;

    void addLast(T item) override;

    void printDeque() override;

    void printDequeInfo();

    T removeFirst() override;

    T removeLast() override;

    T get(int index) override;

    ~DequeArray();

private:
    int capacity = 0;
    int arrayHead = 0; // Pointing at the first element in the array.
    int arrayTail = 0; // Pointing at the next place of the last element.
    T* array = nullptr;

    bool isFull();

    void rearrangeArray(int newArrayHead = 0);

    void expandArrayBy(int expCapacity);

    int getRemainingCapacity();

};

#include "DequeArray.tpp"