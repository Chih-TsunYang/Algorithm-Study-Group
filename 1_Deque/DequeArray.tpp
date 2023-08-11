//
// Created by Chih-Tsun Yang on 7/30/23.
//
#ifndef INC_1_DEQUE_DEQUEARRAY_TPP
#define INC_1_DEQUE_DEQUEARRAY_TPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "DequeArray.h"


template<class T> DequeArray<T>::DequeArray(const int capacity){
    this->capacity = capacity;
    this->array = new T[capacity]();
}

template<class T> int DequeArray<T>::getSize(){
    return (this->arrayTail - this->arrayHead);
}

template<class T> void DequeArray<T>::addFirst(T item){
    if (this->isFull())
        this->expandArrayBy(static_cast<int>(this->capacity / 2 + 1));
    if (this->arrayHead <= 0)
        this->rearrangeArray(static_cast<int>(std::ceil(static_cast<float>(this->getRemainingCapacity()) / 5)));
    arrayHead--;
    *(this->array + arrayHead) = item;
}

template<class T> void DequeArray<T>::addLast(T item){
    if (this->isFull())
        this->expandArrayBy(static_cast<int>(this->capacity / 2 + 1));
    if (this->arrayTail >=this->capacity)
        this->rearrangeArray(static_cast<int>(std::floor(static_cast<float>(this->getRemainingCapacity()) / 5)));
    *(this->array + arrayTail) = item;
    arrayTail++;
}

template<class T> void DequeArray<T>::printDeque(){
    std::cout << "[ ";
    int cntPerLine = 0;
    for (int i = 0; i < this->capacity; i++){
        if (cntPerLine >= 8){
            std::cout << std::endl << "  ";
            cntPerLine = 0;
        }
        cntPerLine ++;
        if (i >= this->arrayHead && i < this->arrayTail)
            std::cout << std::setw(8) << *(this->array + i) << "  ";
        else
            std::cout << std::setw(8) << "N/A" << "  ";
    }
    std::cout << " ]" << std::endl;
}

template<class T> void DequeArray<T>::printDequeInfo() {
    std::cout << "Data type: " << typeid(T).name() << std::endl;
    std::cout << "Capacity : " << std::setw(8) << this->capacity << std::endl;
    std::cout << "Size     : " << std::setw(8) << this->getSize() << std::endl;
}

template<class T> T DequeArray<T>::removeFirst(){
    if(this->getSize() > 0) {
        T firstElem = *(this->array + arrayHead);
        arrayHead++;
        return firstElem;
    } else {
        throw(std::length_error("[Error] Attempting to remove element from an empty queue!"));
    }
}

template<class T> T DequeArray<T>::removeLast(){
    if (this->isEmpty()){
        throw(std::length_error("[Error] Attempting to remove element from an empty queue!"));
    }

    if (this->getSize() > 0) {
        T lastElem = *(this->array + arrayTail - 1);
        arrayTail--;
        return lastElem;
    } else {
        throw(std::length_error("[Error] Attempting to remove element from an empty queue!"));
    }
}

template<class T> T DequeArray<T>::get(int index){
    if (this->getSize() > 0) {
        return *(this->array + arrayHead + index);
    } else {
        throw(std::runtime_error("[Error] Attempting to get element from an empty queue!"));
    }
}

template<class T> DequeArray<T>::~DequeArray(){
    this->capacity = 0;
    this->arrayHead = 0;
    this->arrayTail = 0;
    delete[] this->array;
    this->array = nullptr;
}

template<class T> bool DequeArray<T>::isFull(){
    return (this->getSize() >= this->capacity);
}

template<class T> void DequeArray<T>::rearrangeArray(int newArrayHead){
    int arraySize = this->getSize();
    if (arraySize + newArrayHead > this->capacity) {
        this->expandArrayBy(static_cast<int>(this->capacity / 2 + 1));
        newArrayHead = static_cast<int>(std::ceil(static_cast<float>(this->getRemainingCapacity()) / 5));
    }

    if (newArrayHead < this->arrayHead){
        for (int i = this->arrayHead, j = newArrayHead; i < this->arrayTail; i++, j++){
            *(this->array + j) = *(this->array + i);
        }
    } else if (newArrayHead > this->arrayHead){
        for (int i = this->arrayTail - 1, j = newArrayHead + arraySize - 1; i >= this->arrayHead; i--, j--){
            *(this->array + j) = *(this->array + i);
        }
    }

    this->arrayHead = newArrayHead;
    this->arrayTail = newArrayHead + arraySize;
}

template<class T> void DequeArray<T>::expandArrayBy(int expCapacity){
    int newArrayCapacity = this->capacity + expCapacity;
    T* newArray = new T[newArrayCapacity]();

    for (int i = this->arrayHead; i < this->arrayTail; i++) {
        *(newArray + i) = *(this->array + i);
    }
    delete[] this->array;
    this->array = newArray;
    this->capacity = newArrayCapacity;
}

template<class T> int DequeArray<T>::getRemainingCapacity(){
    return this->capacity - this->getSize();
}

#endif //INC_1_DEQUE_DEQUEARRAY_TPP