#ifndef TREENODE_H
#define TREENODE_H

#include <utility>

// forward declaration of tree class
template <typename NODETYPE> class Tree;

template <typename NODETYPE>
class TreeNode
{
    // class Tree can access private data members
    // of TreeNode class
    friend class Tree<NODETYPE>;

    friend void swap(TreeNode<NODETYPE>* a_lhs, TreeNode<NODETYPE>* a_rhs)
    {
        std::swap(a_lhs, a_rhs);
    }

    /*
     * Function: isLeafNode
     * --------------------
     * Function detemine whether the node is leaf node.
     */

    friend bool isLeafNode(const TreeNode<NODETYPE>* const a_node)
    {
        if (a_node != nullptr)
        {
            if (a_node->m_leftNode != nullptr)
                return false;

            if (a_node->m_rightNode != nullptr)
                return false;
        }

        return true;
    }

public:
    using NodeType = NODETYPE;
    using Node = TreeNode<NODETYPE>;

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

    const TreeNode<NODETYPE>* getLeftNode() const
    {
        return m_leftNode;
    }

    const TreeNode<NODETYPE>* getRightNode() const
    {
        return m_rightNode;
    }

    void swap(TreeNode<NODETYPE>* a_other)
    {
        swap(a_other, this);
    }

private:
    TreeNode<NODETYPE>* m_leftNode;
    NODETYPE            m_data;
    TreeNode<NODETYPE>* m_rightNode;
};

#endif
