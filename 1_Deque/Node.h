//
// Created by Chih-Tsun Yang on 8/12/23.
//
#pragma once

template<class T> class Node {
public:
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
    T elem;

    Node();

    Node(T e, Node<T> *prev, Node<T> *next);

    ~Node();
};

#include "Node.tpp"
