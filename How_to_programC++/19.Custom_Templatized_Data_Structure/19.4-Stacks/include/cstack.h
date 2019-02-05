#ifndef CSTACK_H
#define CSTACK_H

// Stack class with composition of List object

#include "list.h"

template <typename STACKTYPE>
class CStack
{
public:
    void push(const STACKTYPE& a_data)
    {
        m_stackList.insertFront(a_data);
    }

    bool pop(STACKTYPE& a_data)
    {
        return m_stackList.removeFront(&a_data);
    }

    bool pop()
    {
        return m_stackList.removeFront();
    }

    bool isEmpty() const
    {
        return m_stackList.isEmpty();   
    }

    const STACKTYPE& top() const
    {
        return m_stackList.firstNode->getData();
    }

    void printStack() const
    {
        m_stackList.print();
    }

private:
    List<STACKTYPE> m_stackList;
};

#endif
