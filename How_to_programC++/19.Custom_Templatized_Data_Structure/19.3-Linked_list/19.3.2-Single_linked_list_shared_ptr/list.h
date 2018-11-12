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
#include <memory>

#include "list_node.h"


template <typename NODETYPE> class List;

template <typename NODETYPE>
std::ostream& operator<<(std::ostream&, const List<NODETYPE>&);


template <typename NODETYPE>
class List
{
    using ListNodePtr = typename ListNode<NODETYPE>::ListNodePtr;
    using ListNodeWeakPtr = std::weak_ptr<ListNode<NODETYPE>>;
    using Compare = std::function<bool(const NODETYPE& lhs,
                                       const NODETYPE& rhs)>;

    /*
     * Friend function: operator<<
     * Usage: List<int> tmpList{1, 2, 3};
     *        std::cout << tmpList;
     * ----------------------------------
     * Method calls output stream operator `<<' to output list contents.
     */

    friend std::ostream& operator<< <NODETYPE>(std::ostream&         out,
                                               const List<NODETYPE>& a_list);

public:

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
        explicit iterator(const iterator& a_iterator)
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
        explicit const_iterator(ListNodePtr a_listNode)
            : m_listNode(a_listNode)
        {
        }

        // move constructor
        const_iterator(const_iterator&& a_iterator)
        {
            m_listNode = std::move(a_iterator.m_listNode);
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
        : m_firstNode(nullptr),
          m_lastNode(nullptr)
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
     * Fill constructor: List
     * Usage List<int> tmpList(5);
     * ---------------------------
     * Fill constructor fill data with default constructor.
     */

    explicit List(size_t a_size)
        : m_firstNode(nullptr),
          m_lastNode(nullptr)
    {
        const NODETYPE node{};
        for (size_t i = 0; i < a_size; ++i) {
            insertBack(node);
        }
    }

    /*
     * Copy constructor: List
     * Usage: List<int> tmpList;
     *        List<int> tmpList1(tmpList);
     * -----------------------------------
     * Copy constructor (poor peformance!).
     */ 

    List(const List<NODETYPE>& a_list)
        : m_firstNode(nullptr),
          m_lastNode(nullptr)
    {
        if (a_list.isEmpty()) {
            // nothing to do
            return;
        }

        ListNodeWeakPtr currentNode(a_list.m_firstNode);

        while (!currentNode.expired()) {
            insertBack(currentNode.lock()->getData());
            currentNode = currentNode.lock()->nextNode();
        }
    }

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
        a_list.m_firstNode.reset();
        a_list.m_lastNode.reset();
    }

    /*
     * Destructor: List
     * Usage: {
     *            List<int> tmpList;
     *        };
     * -----------------------------
     * Class destructor is not neccessary to free memory.
     */

    ~List()
    {
        if (isEmpty()) {
            return;
        }

        ListNodePtr currentNode(m_firstNode);

        while (m_firstNode) {
            currentNode = m_firstNode;
            m_firstNode = currentNode->m_nextNode;
            currentNode.reset();
        }
    }

    /* Copy assignment operator: List
     * Usage: List<int> tmpList{ 1,2,3,4,5,6,7,8,9};
     *        List<int> list = tmpList;
     * --------------------------------------------
     * Copy list assignment operator (poor performance).
     */

    List<NODETYPE>& operator=(const List<NODETYPE>& a_list)
    {
        if (this == &a_list) {
            // nothing to do
            return *this;
        }

        ListNodePtr currentNode(m_firstNode);
        while (m_firstNode) {
            currentNode = m_firstNode;
            m_firstNode = currentNode->m_nextNode;
            currentNode.reset();
        }

        ListNodeWeakPtr node(a_list.m_firstNode);
        while (!node.expired()) {
            insertBack(node.lock()->getData());
            node = node.lock()->nextNode();
        }

        return *this;
    }

    /* Move assignment operator: List
     * Usage: List<int> l1{ 1, 2, 3 };
     *        List<int> l = std::move(l1);
     * ------------------------------------------
     * Class move assignment operator.
     */

    List<NODETYPE>& operator=(List<NODETYPE>&& a_list)
    {
        if (this != &a_list)
        {
            m_firstNode = std::move(a_list.m_firstNode);
            m_lastNode = std::move(a_list.m_lastNode);
            a_list.m_firstNode.reset();
            a_list.m_lastNode.reset();
        }

        return *this;
    }

    ListNodePtr firstNode()
    {
        return m_firstNode;
    }

    ListNodePtr firstNextNode()
    {
        return m_firstNode->m_nextNode;
    }

    ListNodePtr lastNode()
    {
        return m_lastNode;
    }

    ListNodePtr lastNextNode()
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
        return !m_firstNode;
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
     * Function: insert
     * Usage: List<int> tmpList;
     *        tmpList.insert(5, [](const int& a_l, const int& a_r) {
     *                          return a_l < a_r;
     *                       });
     *        tmpList.insert(-10);
     * -------------------------------------------------------------
     * Method inserts new node based on binary function object. By
     * default, node values are inserted in ascending order.
     *
     */

    void insert(const NODETYPE& a_data,
                Compare a_binary_op = std::less<NODETYPE>())
    {
        if (isEmpty()) {
            ListNodePtr newNode = getNewNode(a_data);
            m_firstNode = m_lastNode = newNode;
            return;
        }

        /* Insert node in first position. */
        if (a_binary_op(a_data, m_firstNode->getData())) {
            insertFront(a_data);
            return;
        }

        ListNodeWeakPtr currentNewNode(m_firstNode);
        ListNodeWeakPtr nextNode(m_firstNode->m_nextNode);

        /* Find appropriate position to insert new node after first node. */
        while ( !nextNode.expired() && !a_binary_op(a_data, nextNode.lock()->getData()) ) {
            currentNewNode = nextNode;
            nextNode = currentNewNode.lock()->m_nextNode;
        }

        /* Insert data at back as temporary (or latter final) last node. */
        if (!nextNode.expired()) {
            insertBack(a_data);
            return;
        }

        /* Insert data after first and before last node. */
        ListNodePtr newNode = getNewNode(a_data);
        currentNewNode.lock()->m_nextNode = newNode;
        newNode->m_nextNode = nextNode.lock();
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

        ListNodePtr oldFirstNode(m_firstNode);

        if (m_firstNode == m_lastNode) {
            m_firstNode.reset();
            m_lastNode.reset();
        }
        else {
            m_firstNode = m_firstNode->m_nextNode;
        }

        // copy remove node data
        *a_data = oldFirstNode->m_data;

        // remove old first node
        oldFirstNode.reset();

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
            m_firstNode.reset();
            m_lastNode.reset();
        }
        else {
            // find last node
            ListNodeWeakPtr tmpNode(m_firstNode);

            // find node before last node
            while (tmpNode.lock()->m_nextNode != m_lastNode) {
                tmpNode = tmpNode.lock()->m_nextNode;
            }

            // before last node is new last node
            m_lastNode = tmpNode.lock();
            m_lastNode->m_nextNode.reset();
        }

        // store old node data
        *a_data = oldLastNode->m_data;

        // release memory for removed node
        oldLastNode.reset();

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
            a_list.m_firstNode.reset();
            a_list.m_lastNode.reset();
            return;
        }

        ListNodeWeakPtr currentNode(m_firstNode);
        ListNodeWeakPtr currentNextNode(m_firstNode->m_nextNode);
        ListNodePtr prevNode;
        ListNodePtr mergeNode;

        while (!a_list.isEmpty())
        {
            mergeNode = a_list.m_firstNode;

            // Find node position to be merged into
            while ( (!currentNextNode.expired()) &&
                     a_comp(currentNextNode.lock()->getData(),
                     mergeNode->getData()) )
            {
                currentNode = currentNextNode;
                currentNextNode = currentNode->m_nextNode;
            }

            // Merge node
            prevNode = currentNode.lock();
            currentNode = a_list.moveFirstNode();
            prevNode->setNextNode(currentNode.lock());
            currentNode.lock()->setNextNode(currentNextNode.lock());
        }
    }

    /*
     * Function: print
     * Usage: tmpList.print();
     * -----------------------
     * Method displays all list nodes. Please use
     * overloaded operator `<<' instead.
     */

    void print() const
    {
        if (isEmpty()) {
            return;
        }

        ListNodeWeakPtr currentNode(m_firstNode);

        while (!currentNode.expired()) {
            std::cout << currentNode.lock()->m_data << ' ';
            currentNode = currentNode.lock()->m_nextNode;
        }

        std::cout << std::endl;
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
        if (m_firstNode->m_nextNode == m_lastNode) {
            m_firstNode.swap(m_lastNode);
            m_firstNode->m_nextNode = m_lastNode;
            m_lastNode->m_nextNode = nullptr;
            return;
        }

        ListNodeWeakPtr frontNode(m_firstNode);
        ListNodeWeakPtr backNode(m_lastNode);
        ListNodeWeakPtr beforeFrontNode, beforeBackNode;

        while (frontNode.lock() != backNode.lock() &&
               frontNode.lock()->m_nextNode != backNode.lock() &&
               beforeFrontNode.lock() != backNode.lock())
        {
            // swap front and back node and next nodes, respectively
            std::swap(frontNode, backNode);
            (frontNode.lock()->m_nextNode).swap(backNode.lock()->m_nextNode);

            // update before back next node to point to back node
            beforeBackNode = frontNode;
            while ( !beforeBackNode.expired() &&
                    (beforeBackNode.lock()->m_nextNode != frontNode.lock()) ) {
                beforeBackNode = beforeBackNode.lock()->m_nextNode;
            }

            // dummy pointer prevents deleting temporary single pointer node 
            // used in node manipulation
            ListNodePtr dummyPtr(beforeBackNode.lock()->m_nextNode);
            beforeBackNode.lock()->m_nextNode = backNode.lock();

            // update before front next node
            if ( !beforeFrontNode.expired() &&
                 (beforeFrontNode.lock()->m_nextNode != frontNode.lock()) ) {
                beforeFrontNode.lock()->m_nextNode = frontNode.lock();
            }

            // update before front node and front and back node
            beforeFrontNode = frontNode;
            frontNode = frontNode.lock()->m_nextNode;
            backNode = beforeBackNode;
        }

        if (frontNode.lock()->m_nextNode == backNode.lock()) {
            std::swap(frontNode, backNode);
            (frontNode.lock()->m_nextNode).swap(backNode.lock()->m_nextNode);
            (beforeFrontNode.lock()->m_nextNode).swap(frontNode.lock()->m_nextNode);
        }

        // update new first and last node
        m_firstNode.swap(m_lastNode);
    }

private:
    ListNodePtr m_firstNode;
    ListNodePtr m_lastNode;

    /*
     * Function: getNewNode
     * Usage: ListNode<int>::ListNodePtr node = getNewNode(42);
     * --------------------------------------------------------
     * Method create new list node with node data. Method calls STD
     * new allocator to allocate memory on heap.
     */

    ListNodePtr getNewNode(const NODETYPE& a_data)
    {
        return std::make_shared<ListNode<NODETYPE>>(a_data);
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

template <typename NODETYPE>
std::ostream& operator<<(std::ostream&         out,
                         const List<NODETYPE>& a_list)
{
    std::copy(a_list.cbegin(), a_list.cend(),
              std::ostream_iterator<NODETYPE>(out, " "));
    return out;
}

template <>
std::ostream& operator<<(std::ostream&     out,
                         const List<char>& a_list)
{
    std::copy(a_list.cbegin(), a_list.cend(),
              std::ostream_iterator<char>(out, ""));
    return out;
}

#endif
