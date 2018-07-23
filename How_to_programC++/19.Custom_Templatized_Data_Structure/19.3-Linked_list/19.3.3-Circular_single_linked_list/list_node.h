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

    const NODETYPE& getData() const
    {
	return m_data;
    }
private:
    NODETYPE            m_data;
    ListNode<NODETYPE>* m_nextNode;    
};


#endif
