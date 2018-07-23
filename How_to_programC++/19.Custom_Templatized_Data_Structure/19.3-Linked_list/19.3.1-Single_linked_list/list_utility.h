//
// Utility functions for single non-circular linked list.
//

#ifndef LIST_UTILITY_H
#define LIST_UTILITY_H

#include "list.h"

// Concatenate a second list to a first list
template <typename NODETYPE>
void concatenate(List<NODETYPE>& a_firstList, List<NODETYPE>& a_secondList)
{
    // first list is empty
    if (a_firstList.isEmpty())
    {
        a_firstList.firstNode( a_secondList.firstNode() );
        a_firstList.lastNode( a_secondList.lastNode() );
        return;
    }

    // second list is empty
    if (a_secondList.isEmpty())
    {
        // nothing to do
        return;
    }
    
    // connect last node with appended first node
    a_firstList.lastNextNode( a_secondList.firstNode() );
}

// Merge second list into first
template <typename NODETYPE>
void merge(List<NODETYPE>& a_firstList, List<NODETYPE>& a_secondList)
{
    if (&a_firstList == &a_secondList) {
        // prevent removing same list used to merge into
        return;
    }

    if (a_firstList.isEmpty())
    {
        a_firstList.firstNode( a_secondList.firstNode() );
        a_firstList.lastNode( a_secondList.lastNode() );
        return;
    }

    if (a_secondList.isEmpty())
    {
        // nothing to do
        return;
    }

    // first and next node of first list
    ListNode<NODETYPE>* currentNode(a_firstList.firstNode());
    ListNode<NODETYPE>* currentNextNode(currentNode->nextNode());
    ListNode<NODETYPE>* prevNode(nullptr);
    // mergable node of second list
    ListNode<NODETYPE>* mergeCurrentNode(a_secondList.firstNode());
    ListNode<NODETYPE>* mergeNextNode(nullptr);

    while ( mergeCurrentNode != nullptr )
    {
        // inspect next node value with mergable node value
        while ( (currentNextNode != nullptr) && 
    	    (currentNextNode->getData() < mergeCurrentNode->getData()) )
        {
	   currentNode = currentNextNode;
    	   // inspect next node data
    	   currentNextNode = currentNextNode->nextNode();
        }

        // current node and next mergable node before merge
        prevNode = currentNode;
        mergeNextNode = mergeCurrentNode->nextNode();

        // merge current node and update link to merged node and 
        // link from merged node
        currentNode = mergeCurrentNode;
        prevNode->setNextNode(currentNode);
        currentNode->setNextNode(currentNextNode);

        // shift to next mergable node
        mergeCurrentNode = mergeNextNode;
    }
}

#endif
