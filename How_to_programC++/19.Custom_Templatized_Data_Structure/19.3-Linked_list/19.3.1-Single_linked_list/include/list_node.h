#ifndef LIST_NODE_H
#define LIST_NODE_H

// forward declaration of class List that can be used
// as the class friend member.
template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode
{
    // class List can access class ListNode private data members
    friend class List<NODETYPE>;
public:
    explicit ListNode(const NODETYPE& a_data)
        : m_data(a_data),
          m_nextNode(nullptr)
    {
    }

    // Move constructor
    explicit ListNode(ListNode<NODETYPE>&& a_listNode)
    {
        m_data = std::move(a_listNode.m_data);
        m_nextNode = a_listNode.m_nextNode;
        a_listNode.m_nextNode = nullptr;
    }

    // Copy assignment operator
    ListNode<NODETYPE>& operator=(const ListNode<NODETYPE>& a_listNode)
    {
        if (this != &a_listNode)
        {
            m_data = a_listNode.m_data;
            m_nextNode = a_listNode.m_nextNode;
        }

        return *this;
    }

    // Move assignment operator
    ListNode<NODETYPE>& operator=(ListNode<NODETYPE>&& a_listNode)
    {
        if (this != &a_listNode)
        {
            m_data = std::move(a_listNode.m_data);
            m_nextNode = a_listNode.m_nextNode;
            a_listNode.m_nextNode = nullptr;
        }

        return *this;
    }

    const NODETYPE& getData() const
    {
        return m_data;
    }

    void setNextNode(ListNode<NODETYPE>* a_nextNode)
    {
        m_nextNode = a_nextNode;
    }

    ListNode<NODETYPE>* nextNode()
    {
        return m_nextNode;
    }

    const ListNode<NODETYPE>* nextNode() const
    {
        return m_nextNode;
    }

private:
    NODETYPE            m_data;
    ListNode<NODETYPE>* m_nextNode;
};


#endif
