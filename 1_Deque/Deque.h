/*
	Homework1

	1. Create a class inherit the below class Deque
	   by using array data structure.
	2. Create a class inherit the below class Deque
	   by using linked list data structure.

	Requirement:
	You are not allowed to use any C's/C++'s built in data structure class,
	including dynamic array, vector.
	All you can use are basic array and the classes built by yourselves.
	The only function you can to use from C++'s libraries is "cout" to print content on the console.
*/

#pragma once

/// <summary>
/// double end queue
/// </summary>
/// <typeparam name="T"> the type of the item that the deque hold</typeparam>
template<class T> class Deque {
public:
    /// <summary>
    /// return quantity of items in the Deque
    /// </summary>
    /// <returns> quantity of items in the Deque </returns>
    virtual int getSize() = 0;

    /// <summary>
    /// add the item at the beginning of the Deque
    /// </summary>
    /// <param name="item"></param>
    virtual void addFirst(T item) = 0;

    /// <summary>
    /// add the item at the end of the Deque
    /// </summary>
    /// <param name="item"></param>
    virtual void addLast(T item) = 0;

    /// <summary>
    /// return true if Deque is empty
    /// </summary>
    /// <returns> true if the Deque is empty </returns>
    bool isEmpty()
    {
        return getSize() == 0;
    }

    /// <summary>
    /// print out all items in the deque, seperate by the space, " "
    /// </summary>
    virtual void printDeque() = 0;

    /// <summary>
    /// remove the first item of the Deque
    /// </summary>
    /// <returns> the removed item </returns>
    virtual T removeFirst() = 0;

    /// <summary>
    /// remove the last item of the Deque
    /// </summary>
    /// <returns> the removed item </returns>
    virtual T removeLast() = 0;

    /// <summary>
    /// given the index and return the item at the position given index
    /// </summary>
    /// <param name="index"></param>
    /// <returns> the item at the index </returns>
    virtual T get(int index) = 0;
};
