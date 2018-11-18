/*
 * Implementation forward list structure.
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <initializer_list>
#include <functional>
#include <algorithm>
#include <iterator>
#include "list_node.h"


template <typename NODETYPE>
class List
{
    /*
     * Friend function: operator<<
     * Usage: List<int> tmpList{1, 2, 3};
     *        std::cout << tmpList;
     * ----------------------------------
     * Method calls output stream operator `<<' to output list contents.
     */

    friend std::ostream& operator<<(std::ostream& out, const List<NODETYPE>& a_list)
    {
        std::copy(a_list.cbegin(), a_list.cend(),
                  std::ostream_iterator<NODETYPE>(out, " "));
        return out;
    }

    typedef std::function<bool(const NODETYPE& lhs, const NODETYPE& rhs)> Compare;

public:

    using ListNodePtr = ListNode<NODETYPE>*;

    /*
     * Class: iterator
     * Usage: List<int>::iterator it;
     * ------------------------------
     * Helper class to access list nodes.
     */

    class iterator
    {
    public:
        // iterator traits
        using value_type = NODETYPE;
        using difference_type = ptrdiff_t;
        using pointer = NODETYPE*;
        using reference = NODETYPE&;
        using iterator_category = std::forward_iterator_tag;

        // default constructor
        iterator()
            : m_listNode(nullptr)
        {
        }

        // copy constructor
        iterator(const iterator& a_iterator)
            : m_listNode(a_iterator.m_listNode)
        {
        }

        // copy constructor
        explicit iterator(ListNodePtr a_listNode)
            : m_listNode(a_listNode)
        {
        }

        // move constructor
        iterator(iterator&& a_iterator)
        {
            m_listNode = std::move(a_iterator.m_listNode);
            a_iterator.m_listNode = nullptr;
        }

        // copy assignment
        iterator& operator=(const iterator& a_iterator)
        {
            if (this != &a_iterator) {
                m_listNode = a_iterator.m_listNode;
            }

            return *this;
        }

        // move assigment
        iterator& operator=(iterator&& a_iterator)
        {
            if (this != &a_iterator) {
                m_listNode = std::move(a_iterator.m_listNode);
                a_iterator.m_listNode = nullptr;
            }

            return *this;
        }

        // dereference
        reference operator*() const
        {
           return m_listNode->m_data;
        }

        // preincrement
        iterator& operator++()
        {
            m_listNode = m_listNode->nextNode();
            return *this;
        }

        // postincrement
        iterator operator++(int)
        {
            iterator iter(*this);
            operator++();
            return iter;
        }

        bool operator!=(const iterator& a_iterator)
        {
            return (m_listNode != a_iterator.m_listNode);
        }

        bool operator==(const iterator& a_iterator)
        {
            return !(operator!=(a_iterator));
        }

    private:
        ListNodePtr m_listNode;
    }; // end iterator

    /*
     * Class: const_iterator
     * Usage: List<int>::const_iterator cit;
     * -------------------------------------
     * Helper class to access list nodes and iterate over list.
     */

    class const_iterator
    {
    public:
        // iterator traits
        using value_type = NODETYPE;
        using difference_type = ptrdiff_t;
        using pointer = const NODETYPE*;
        using reference = const NODETYPE&;
        using iterator_category = std::forward_iterator_tag;

        // default constructor
        const_iterator()
            : m_listNode(nullptr)
        {
        }

        // copy constructor
        const_iterator(const const_iterator& a_iterator)
            : m_listNode(a_iterator.m_listNode)
        {
        }

        // copy constructor
        explicit const_iterator(const ListNodePtr a_listNode)
            : m_listNode(a_listNode)
        {
        }

        // move constructor
        const_iterator(const_iterator&& a_iterator)
        {
            m_listNode = std::move(a_iterator.m_listNode);
            //a_iterator.m_listNode = nullptr;
        }

        // copy assignment
        const_iterator& operator=(const const_iterator& a_iterator)
        {
            if (this != &a_iterator) {
                m_listNode = a_iterator.m_listNode;
            }

            return *this;
        }

        // move assigment
        const_iterator& operator=(const_iterator&& a_iterator)
        {
            if (this != &a_iterator) {
                m_listNode = std::move(a_iterator.m_listNode);
                //a_iterator.m_listNode = nullptr;
            }

            return *this;
        }

        // dereference
        reference operator*() const
        {
           return m_listNode->m_data;
        }

        // preincrement
        const_iterator& operator++()
        {
            m_listNode = m_listNode->nextNode();
            return *this;
        }

        // postincrement
        const_iterator operator++(int)
        {
            const_iterator iter(*this);
            operator++();
            return iter;
        }

        bool operator!=(const const_iterator& a_iterator)
        {
            return (m_listNode != a_iterator.m_listNode);
        }

        bool operator==(const const_iterator& a_iterator)
        {
            return !(operator!=(a_iterator));
        }

    private:
        ListNodePtr m_listNode;
    }; // end iterator

    /*-------------------------------------------------------------------------*/
    /*
     * Constructor: List()
     * Usage: List<int> tmpList;
     * -------------------------
     * Default list constructor.
     */

    List()
        : m_firstNode(nullptr), m_lastNode(nullptr)
    {
    }

    /*
     * Constructor: List
     * Usage: List<int> tmpList{1, 2, 3};
     * ----------------------------------
     * Constructor list initialization using initializer_list.
     */

    List(std::initializer_list<NODETYPE> a_data)
        : m_firstNode(nullptr),
          m_lastNode(nullptr)
    {
        for (const auto& data : a_data) {
            insertBack(data);
        }
    }

    /*
     * Copy constructor: List
     * Usage: List<int> tmpList;
     *        List<int> tmpList1(tmpList);
     * -----------------------------------
     * Prevent using copy constructor (due to bad peformance).
     */ 

    List(const List<NODETYPE>& a_list) = delete;

    /*
     * Move constructor: List
     * Usage: List<int> tmpList;
     *        List<int> tmpList1( std::move(tmpList) );
     * -----------------------------------
     * Move list constructor.
     */ 

    List(List<NODETYPE>&& a_list)
    {
        m_firstNode = std::move(a_list.m_firstNode);
        m_lastNode = std::move(a_list.m_lastNode);
        a_list.m_firstNode = nullptr;
        a_list.m_lastNode = nullptr;
    }

    /*
     * Destructor: List
     * Usage: {
     *            List<int> tmpList;
     *        };
     * -----------------------------
     * Class destructor.
     */

    ~List()
    {
        if (isEmpty()) {
            return;
        }

        ListNodePtr currentNode(m_firstNode);
        while (m_firstNode != nullptr)
        {
            currentNode = m_firstNode;
            m_firstNode = m_firstNode->m_nextNode;
            delete currentNode;
            currentNode = nullptr;
        }
    }

    // Prevent List copy assignment (due to bad performance).
    ListNode<NODETYPE>& operator=(const List<NODETYPE>& a_list) = delete;

    // Move assignment operator
    ListNode<NODETYPE>& operator=(ListNode<NODETYPE>&& a_list)
    {
        if (this != &a_list)
        {
            m_firstNode = std::move(a_list.m_firstNode);
            m_lastNode = std::move(a_list.m_lastNode);
            a_list.m_firstNode = nullptr;
            a_list.m_lastNode = nullptr;
        }

        return *this;
    }

    ListNodePtr firstNode()
    {
        return m_firstNode;
    }    

    ListNodePtr firstNode() const
    {
        return m_firstNode;
    }    

    ListNodePtr firstNextNode()
    {
        return m_firstNode->m_nextNode;
    }

    ListNodePtr firstNextNode() const
    {
        return m_firstNode->m_nextNode;
    }

    ListNodePtr lastNode()
    {
        return m_lastNode;
    }

    ListNodePtr lastNode() const
    {
        return m_lastNode;
    }
 
    ListNodePtr lastNextNode()
    {
        return m_lastNode->m_nextNode;
    }
 
    ListNodePtr lastNextNode() const
    {
        return m_lastNode->m_nextNode;
    }

    void firstNode(ListNodePtr a_firstNode)
    {
        m_firstNode = a_firstNode;
    }

    void firstNextNode(ListNodePtr a_nextNode)
    {
        m_firstNode->m_nextNode = a_nextNode;
    }

    void lastNode(ListNodePtr a_lastNode)
    {
        m_lastNode = a_lastNode;
    }

    void lastNextNode(ListNodePtr a_nextNode)
    {
        m_lastNode->m_nextNode = a_nextNode;
    }

    /*
     * Function: begin
     * Usage: List<int> tmpList;
     *        List<int>::iterator it = tmpList.begin();
     * ------------------------------------------------
     * Method return iterator to first node in a list.
     */

    iterator begin()
    {
        return iterator(m_firstNode);
    }

    /*
     * Function: cbegin
     * Usage: List<int> tmpList;
     *        List<int>::const_iterator it = tmpList.cbegin();
     * -------------------------------------------------------
     * Method return constant iterator to first node in a list.
     * Only read accessed is allowed to a list.
     */

    const_iterator cbegin() const
    {
        return const_iterator(m_firstNode);
    }

    /*
     * Function: end
     * Usage: List<int> tmpList;
     *        List<int>::iterator it = tmpList.end();
     * ------------------------------------------------
     * Method return iterator to one list node past the last list node.
     * This node is always null.
     */

    iterator end()
    {
        return iterator(nullptr);
    }

    /*
     * Function: cend
     * Usage: List<int> tmpList;
     *        List<int>::const_iterator it = tmpList.cend();
     * -----------------------------------------------------
     * Method return constant iterator to one list node past the last list node.
     * Only read accessed is allowed to a list.
     */

    const_iterator cend() const
    {
        return const_iterator(nullptr);
    } 

    /*
     * Function: isEmpty
     * Usage: List<int> tmpList;
     *        tmpList.isEmpty();
     * -----------------------------
     * Method determine the list is not empty. List is empty if
     * first node is empty.
     */

    bool isEmpty() const
    {
        return m_firstNode == nullptr;
    }

    /*
     * Function: insertFront
     * Usage: List<int> tmpList;
     *        tmpList.insertFront(5);
     * -----------------------------
     * Method insert new node with node data to the first place in list.
     */

    void insertFront(const NODETYPE& a_data)
    {
        // create new node
        ListNodePtr newNode = getNewNode(a_data);
        
        if (isEmpty()) {
            // First node is also the last node
            m_firstNode = m_lastNode = newNode;
        }
        else {
            // old first node place on new second place
            newNode->m_nextNode = m_firstNode;

            // new node is in new first place
            m_firstNode = newNode;
        }
    }

    /*
     * Function: insertBack
     * Usage: List<int> tmpList;
     *        tmpList.insertBack(5);
     * -----------------------------
     * Method insert new node with node data to the last place in list.
     */

    void insertBack(const NODETYPE& a_data)
    {
        ListNodePtr newNode = getNewNode(a_data);

        if (isEmpty()) {
            m_firstNode = m_lastNode = newNode;
        }
        else {
            // update previous last node to point to new last node
            m_lastNode->m_nextNode = newNode;

            // new last node
            m_lastNode = newNode;
        }
    }

    /*
     * Function: removeFront
     * Usage: int a; tmpList.removeFront(&a);
     * -------------------------------------
     * Method removes first node and its data is stored in function argument.
     */

    bool removeFront(NODETYPE* a_data)
    {
        if (isEmpty()) {
            // nothing to do
            return false;
        }

        ListNodePtr oldFirstNode = m_firstNode;

        if (m_firstNode == m_lastNode) {
            m_firstNode = m_lastNode = nullptr;
        }
        else {
            m_firstNode = m_firstNode->m_nextNode;
        }

        // copy remove node data
        *a_data = oldFirstNode->m_data;

        // remove old first node
        delete oldFirstNode;
        oldFirstNode = nullptr;
        
        return true;
    }

    /*
     * Function: removeBack
     * Usage: int a; tmpList.removeBack(&a);
     * -------------------------------------
     * Method searches last node starting from the first node. Last node is
     * removed and its data is stored in function argument.
     * NOTE: bad performance: remove last node (O(N)),
     *       remove first node (O(1)), on average (O(N) + const.)
     */

    bool removeBack(NODETYPE* a_data)
    {
        if (isEmpty()) {
            // nothing to do
            return false;
        }

        ListNodePtr oldLastNode = m_lastNode;
        
        if (m_firstNode == m_lastNode) {
            m_firstNode = m_lastNode = nullptr;
        }
        else {
            // find last node
            ListNodePtr tmpNode = m_firstNode;

            // find node before last node
            while (tmpNode->m_nextNode != m_lastNode) {
                tmpNode = tmpNode->m_nextNode;
            }

            // before last node is new last node
            m_lastNode = tmpNode;
            m_lastNode->m_nextNode = nullptr;
        }

        // store old node data
        *a_data = oldLastNode->m_data;

        // release memory for removed node
        delete oldLastNode;
        oldLastNode = nullptr;

        return true;
    }

    /*
     * Function: merge
     * Usage: list1.merge(list2);
     * --------------------------
     * Merge algorithm merge target list into current list. Each target node is
     * sequentially moved to current list. Moving process preserve original list,
     * target list nodes ownership is transfered to new owner current list.
     */

    void merge(List<NODETYPE>& a_list, Compare a_comp = std::less<NODETYPE>())
    {
        if (this == &a_list) {
            // trivial merge
            return;
        }

        if (a_list.isEmpty()) {
            // trivial merge
            return;
        }

        if (isEmpty())
        {
            m_firstNode = std::move(a_list.m_firstNode);
            m_lastNode = std::move(a_list.m_lastNode);
            a_list.m_firstNode = nullptr;
            a_list.m_lastNode = nullptr;
            return;
        }

        ListNodePtr currentNode = m_firstNode;
        ListNodePtr currentNextNode = m_firstNode->m_nextNode;
        ListNodePtr prevNode = currentNode;
        ListNodePtr mergeNode(nullptr);

        while (!a_list.isEmpty())
        {
            mergeNode = a_list.m_firstNode;

            // Find node position to be merged into
            while ( (currentNextNode != nullptr) &&
                    a_comp(currentNextNode->getData(), mergeNode->getData()) )
            {
                currentNode = currentNextNode;
                currentNextNode = currentNode->m_nextNode;
            }

            // Merge node
            prevNode = currentNode;
            currentNode = a_list.moveFirstNode();
            prevNode->setNextNode(currentNode);
            currentNode->setNextNode(currentNextNode);
        }
    }

    /*
     * Function: reverse
     * Usage: tmpList.reverse();
     * ------------------------
     * Method reverse list order.
     *
     */

    void reverse()
    {
        // one node
        if (m_firstNode == m_lastNode) {
            // nothing to do
            return;
        }

        // two nodes
        if (m_firstNode && m_firstNode->m_nextNode == m_lastNode) {
            std::swap(m_firstNode, m_lastNode);
            m_firstNode->m_nextNode = m_lastNode;
            m_lastNode->m_nextNode = nullptr;
            return;
        }

        ListNode<NODETYPE>* frontNode = m_firstNode;
        ListNode<NODETYPE>* backNode = m_lastNode;
        ListNode<NODETYPE>* beforeFrontNode = nullptr;
        ListNode<NODETYPE>* beforeBackNode = nullptr;

        while ((frontNode != backNode) && (frontNode->m_nextNode != backNode) &&
               (beforeFrontNode != backNode))
        {
            // swap front and back node and next nodes, respectively
            std::swap(frontNode, backNode);
            std::swap(frontNode->m_nextNode, backNode->m_nextNode);

            // update before back next node to point to back node
            beforeBackNode = frontNode;
            while ( (beforeBackNode != nullptr) &&
                    (beforeBackNode->m_nextNode != frontNode) ) {
                beforeBackNode = beforeBackNode->m_nextNode;
            }

            // dummy pointer prevents deleting temporary single pointer node 
            // used in node manipulation
            beforeBackNode->m_nextNode = backNode;

            // update before front next node
            if ( (beforeFrontNode != nullptr) &&
                 (beforeFrontNode->m_nextNode != frontNode) ) {
                beforeFrontNode->m_nextNode = frontNode;
            }

            // update before front node and front and back node
            beforeFrontNode = frontNode;
            frontNode = frontNode->m_nextNode;
            backNode = beforeBackNode;
        }

        if ((frontNode != nullptr) && (frontNode->m_nextNode == backNode)) {
            std::swap(frontNode, backNode);
            std::swap(frontNode->m_nextNode, backNode->m_nextNode);
            std::swap(beforeFrontNode->m_nextNode, frontNode->m_nextNode);
        }

        // update new first and last node
        std::swap(m_firstNode, m_lastNode);
    }

    /*
     * Function: print
     * Usage: tmpList.print();
     * -----------------------
     * Method displays all list nodes.
     */

    void print() const
    {
    if (isEmpty()) {
        return;
    }

    ListNodePtr currentNode = m_firstNode;

    while (currentNode != nullptr) {
        std::cout << currentNode->m_data << ' ';
        currentNode = currentNode->m_nextNode;
    }

    std::cout << std::endl;
    }

private:
    ListNodePtr m_firstNode;
    ListNodePtr m_lastNode;

    /*
     * Function: getNewNode
     * Usage: ListNode<int> node = getNewNode(42);
     * -------------------------------------------
     * Method create new list node with node data. Method calls STD
     * new allocator to allocate memory on heap.
     */

    ListNodePtr getNewNode(const NODETYPE& a_data)
    {
        return new ListNode<NODETYPE>(a_data);
    }

    /*
     * Function: moveFirstNode()
     * Usage: ListNode<int> a = moveFirstNode();
     * -----------------------------------------
     * Method moves first node. Next new node is next node in moved first node.
     */

    ListNodePtr moveFirstNode()
    {
        ListNodePtr nextFirstNode = m_firstNode->m_nextNode;
        ListNodePtr firstNode = std::move(m_firstNode);
        m_firstNode = nextFirstNode;
        return firstNode;
    }

};// end class List


#endif
