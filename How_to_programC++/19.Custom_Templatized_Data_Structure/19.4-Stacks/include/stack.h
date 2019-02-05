#ifndef STACK_H
#define STACK_H

#include "list.h"

template <typename STACKTYPE>
class Stack : private List<STACKTYPE>
{
public:
    // implement stack push method (insert on top of stack)
    void push(const STACKTYPE& a_data)
    {
        this->insertFront(a_data);
    }

    // implement stack pop method (remove top of stack)
    bool pop(STACKTYPE& a_data)
    {
        return this->removeFront(&a_data);	
    }

    bool pop()
    {
        return this->removeFront();
    }

    bool isEmpty() const
    {
        return List<STACKTYPE>::isEmpty();
    }

    const STACKTYPE& top() const
    {
        return this->firstNode()->getData();
    }

    void printStack() const
    {
        this->print();	
    }
};

#endif
