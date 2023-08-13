cmake_minimum_required(VERSION 3.25)
project(1_Deque)

set(CMAKE_CXX_STANDARD 20)

add_executable(1_Deque main.cpp DequeArray.tpp DequeLinkedList.tpp Node.h Node.tpp DequeLinkedList.h)
