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
    using ListNodePtr = std::shared_ptr<ListNode<NODETYPE>>;

    explicit ListNode(const NODETYPE& a_data)
	: m_data(a_data),
	  m_nextNode(nullptr)
    {
    }

    // Move constructor
    ListNode(ListNode<NODETYPE>&& a_listNode)
    {
	m_data = std::move(a_listNode.m_data);
	m_nextNode = std::move(a_listNode.m_nextNode);
	a_listNode.m_nextNode.reset();
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
	    m_nextNode = std::move(a_listNode.m_nextNode);
	    a_listNode.m_nextNode.reset();
	}

	return *this;
    }

    const NODETYPE& getData() const
    {
	return m_data;
    }

    void setNextNode(ListNodePtr a_nextNode)
    {
	m_nextNode = a_nextNode;
    }

    ListNodePtr nextNode()
    {
	return m_nextNode;
    }
    
    const ListNodePtr nextNode() const
    {
	return m_nextNode;
    }

private:
    NODETYPE    m_data;
    ListNodePtr m_nextNode;    
};


#endif
