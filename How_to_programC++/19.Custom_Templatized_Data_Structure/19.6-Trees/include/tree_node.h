#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of tree class
template <typename NODETYPE> class Tree;

template <typename NODETYPE>
class TreeNode
{
    // class Tree can access private data members
    // of TreeNode class
    friend class Tree<NODETYPE>;
public:
    TreeNode(const NODETYPE& a_data)
	: m_leftNode(nullptr),
	  m_data(a_data),
	  m_rightNode(nullptr)
    {
    }

    const NODETYPE& getData() const
    {
	return m_data;
    }
private:
    TreeNode<NODETYPE>* m_leftNode;
    NODETYPE            m_data;
    TreeNode<NODETYPE>* m_rightNode;
};

#endif
