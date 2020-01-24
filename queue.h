//lang::CwC
#pragma once

#include "object.h"
#include <cstdlib>

/**
 * Queue: Represents a FIFO data structure.
 *        Capable of holding any Object in the given order.
 *
 * mutable
 *
 * authors: dermer.s@husky.neu.edu && Sarialli.n@northeastern.edu
 */
class Queue : public Object {
public:
    // The Constructor
    Queue() {}

    // The Destructor
    virtual ~Queue() {}

    // adds the given object to the beginning of this queue.
    // undefined behavior: the same pointer is pushed more than once or o is this
    virtual void push(Object* o) {}

    // removes and returns the object at the end of this queue.
    // errors if there is nothing in the queue
    virtual Object* pop() {}

    // returns the object at the end of this queue but does not remove it.
    // errors if there is nothing in the queue
    virtual Object* peek() {}

    // gives the total number of elements in this Queue
    virtual size_t len() {}

    // true if o is a queue and all of the elements of this queue,
    // in the same order, are equal to o's
    virtual bool equals(Object *other) {}

    // hash of this queue
    virtual size_t hash() {}
};