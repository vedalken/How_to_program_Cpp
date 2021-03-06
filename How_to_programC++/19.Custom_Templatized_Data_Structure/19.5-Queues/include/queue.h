#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <typename QUEUE_TYPE>
class Queue : private List<QUEUE_TYPE>
{
public:
    // implement push on top (or enqueue)
    void enqueue(const QUEUE_TYPE& a_data)
    {
        this->insertBack(a_data);
    }

    // implement pop in front (or dequeue)
    bool dequeue(QUEUE_TYPE& a_data)
    {
        return this->removeFront(&a_data);
    }

    bool empty() const
    {
        // resolve non-dependent name to dependent name
        return this->isEmpty();
    }

    void print() const
    {
        // resolve non-dependent name to dependent name
        List<QUEUE_TYPE>::print();
    }
};

#endif
