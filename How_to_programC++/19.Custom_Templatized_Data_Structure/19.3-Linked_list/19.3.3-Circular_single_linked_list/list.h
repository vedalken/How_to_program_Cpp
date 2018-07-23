/* Implementation circular single linked list. */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "list_node.h"


template <typename NODETYPE>
class List
{
public:
    // default constructor
    List()
	: m_firstNode(nullptr), m_lastNode(m_firstNode)
    {
    }

    ~List()
    {
	if (isEmpty()) {
	    // nothing to do
	    return;
	}

	ListNode<NODETYPE>* tmpNode(m_firstNode);

	while (!isEmpty())
	{
	    if (m_firstNode == m_lastNode) {
	        m_firstNode = m_lastNode = nullptr;
	        break;
	    }

	    tmpNode = m_firstNode;
	    m_firstNode = m_firstNode->m_nextNode;
	    delete tmpNode;
	    tmpNode = nullptr;
	}
    }

    inline bool isEmpty() const
    {
	return m_firstNode == nullptr;
    }

    // Insert new node in front of list
    void insertFront(const NODETYPE& a_data)
    {
	// create new node
	ListNode<NODETYPE>* newNode = getNewNode(a_data);
		
	if (isEmpty()) {
	    // First node is also the last node
	    m_firstNode = m_lastNode = newNode;
	    m_lastNode->m_nextNode = m_firstNode;
	}
	else {
	    // old first node place on new second place
	    newNode->m_nextNode = m_firstNode;         // X -> A -> B

	    // new node is in new first place
	    m_firstNode = newNode;                     // X new node

	    // update last node to point to new node
	    m_lastNode->m_nextNode = m_firstNode;      // B -> X
	}
    }

    // Insert new node at back (at last place) in list
    void insertBack(const NODETYPE& a_data)
    {
	ListNode<NODETYPE>* newNode = getNewNode(a_data);

	if (isEmpty()) {
	    m_firstNode = m_lastNode = newNode;
	    m_lastNode->m_nextNode = m_firstNode;
	}
	else {
	    // update previous last node (B) to point to new last node (X)
	    m_lastNode->m_nextNode = newNode;   // A -> B -> X

	    // new last node (X)
	    m_lastNode = newNode;     // X new last node

	    // update new last node (X) to point to first node (A)
	    m_lastNode->m_nextNode = m_firstNode; //  X -> A
	}
    }
    
    bool removeFront()
    {
	NODETYPE dummy{};
	return removeFront(&dummy);	
    }

    // Remove node from front of list. Store removed data.
    bool removeFront(NODETYPE* a_data)
    {
	if (isEmpty()) {
	    // nothing to do
	    return false;
	}

	ListNode<NODETYPE>* oldFirstNode = m_firstNode;

	if (m_firstNode == m_lastNode) {
	    m_firstNode = m_lastNode = nullptr;
	}
	else {
	    m_firstNode = m_firstNode->m_nextNode;
	    m_lastNode->m_nextNode = m_firstNode;
	}

	// copy remove node data
	*a_data = oldFirstNode->m_data;

	// remove old first node
	delete oldFirstNode;
	oldFirstNode = nullptr;
	
	return true;
    }

    // Remove node from back of list. Store removed data.
    bool removeBack(NODETYPE* a_data)
    {
	if (isEmpty()) {
	    // nothing to do
	    return false;
	}

	ListNode<NODETYPE>* oldLastNode = m_lastNode;
	
	if (m_firstNode == m_lastNode) {
	    m_firstNode = m_lastNode = nullptr;
	}
	else {
	    // find last node
	    ListNode<NODETYPE>* tmpNode = m_firstNode;

	    // find node before last node
	    while (tmpNode->m_nextNode != m_lastNode) {
		tmpNode = tmpNode->m_nextNode;
	    }

	    // before last node is new last node
	    m_lastNode = tmpNode;
	    m_lastNode->m_nextNode = m_firstNode;
	}

	// store old node data
	*a_data = oldLastNode->m_data;

	// release memory for removed node
	delete oldLastNode;
	oldLastNode = nullptr;

	return true;
    }

    // display list contents
    void print() const
    {
	if (isEmpty()) {
	    std::cout << "The list is empty\n\n";
	    return;
	}

	std::cout << "The list is: ";
	ListNode<NODETYPE>* currentNode = m_firstNode;

	do {
	    std::cout << currentNode->m_data << ' ';
	    currentNode = currentNode->m_nextNode;
	} while (currentNode != m_firstNode);

	std::cout << "\n\n";
    }

private:
    ListNode<NODETYPE>* m_firstNode;
    ListNode<NODETYPE>* m_lastNode;

    // utility function to allocate new node
    ListNode<NODETYPE>* getNewNode(const NODETYPE& a_data)
    {
	return new ListNode<NODETYPE>(a_data);
    }
};// end class List


#endif
