#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "tree_node.h"

template <typename NODETYPE>
class Tree
{
    typedef typename TreeNode<NODETYPE>::TreeNodePtr TreeNodePtr;
public:
    Tree() : m_rootNode(nullptr)
    {
    }

    ~Tree()
    {
	//deleteNodeHelper( m_rootNode );
    }

    void insertNode(const NODETYPE& a_data)
    {
	insertNodeHelper( m_rootNode, a_data );
    }

    void preOrderTraversal() const
    {
	preOrderHelper( m_rootNode );
    }

    void inOrderTraversal() const
    {
	inOrderHelper( m_rootNode );
    }

    void postOrderTraversal() const
    {
	postOrderHelper( m_rootNode );
    }

private:
    TreeNodePtr m_rootNode;

    // Attach node to root node.
    // Helper method modifies the pointer's data, instead of passing
    // "as a pointer" we have to pass the address of that pointer
    // that's contents is being modified. In this case we add another
    // tree node with node data. Another case we could declare
    // function parameter type as *& (reference to pointer) instead
    // of ** (pointer to pointer or shortly pptr).
    void insertNodeHelper(TreeNodePtr&     a_ptr,
			  const NODETYPE&  a_data)
    {
	if (a_ptr == nullptr) {
	    // Empty tree node.
	    a_ptr = std::make_shared<TreeNode<NODETYPE>>(a_data);
	}
	else {
	    if ( a_data < a_ptr->m_data ) {
		insertNodeHelper( a_ptr->m_leftNode, a_data );
	    }
	    else {
		if (a_data > a_ptr->m_data) {
		    insertNodeHelper( a_ptr->m_rightNode, a_data );
		}
		else {
		    std::cout << a_data << " duplicate" << std::endl;
		}
	    }
	}
    }
    
    // Recursively delete nodes in postorder traversal of Tree
    void deleteNodeHelper(TreeNodePtr& a_ptr)
    {
	if (a_ptr != nullptr) {
	    deleteNodeHelper( a_ptr->m_leftNode );
	    deleteNodeHelper( a_ptr->m_rightNode );
	    // Delete root node.
	    a_ptr.reset();
	}
    }

    // Preorder processing tree nodes without tree modifications
    void preOrderHelper(TreeNodePtr a_ptr) const
    {
	if (a_ptr != nullptr) {
	    std::cout << a_ptr->m_data << ' ';
	    preOrderHelper(a_ptr->m_leftNode);
	    preOrderHelper(a_ptr->m_rightNode);
	}
    }

    // Inorder processing tree nodes without tree modifications
    void inOrderHelper(TreeNodePtr a_ptr) const
    {
	if (a_ptr != nullptr) {
	    inOrderHelper(a_ptr->m_leftNode);
	    std::cout << a_ptr->m_data << ' ';
	    inOrderHelper(a_ptr->m_rightNode);
	}
    }

    // Postorder processing tree nodes without tree modifications
    void postOrderHelper(TreeNodePtr a_ptr) const
    {
	if (a_ptr != nullptr) {
	    postOrderHelper(a_ptr->m_leftNode);
	    postOrderHelper(a_ptr->m_rightNode);
	    std::cout << a_ptr->m_data << ' ';
	}
    }
};

#endif
