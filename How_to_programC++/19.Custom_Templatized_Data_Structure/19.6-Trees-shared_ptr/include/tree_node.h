#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

// forward declaration of tree class
template <typename NODETYPE> class Tree;

template <typename NODETYPE>
class TreeNode
{
    // class Tree can access private data members
    // of TreeNode class
    friend class Tree<NODETYPE>;
public:
    typedef std::shared_ptr<TreeNode<NODETYPE>> TreeNodePtr;

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
    TreeNodePtr m_leftNode;
    NODETYPE    m_data;
    TreeNodePtr m_rightNode;
};

#endif
