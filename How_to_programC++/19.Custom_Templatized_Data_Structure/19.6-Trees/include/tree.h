#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <functional>
#include "tree_node.h"

template <typename NODETYPE>
class Tree
{
private:
    TreeNode<NODETYPE>* m_rootNode;

public:
    Tree() : m_rootNode(nullptr)
    {
    }

    ~Tree()
    {
        deleteNodeHelper(&m_rootNode);
    }

    const TreeNode<NODETYPE>* getRootNode() const
    {
        return m_rootNode;
    }

    void insertNode(NODETYPE&& a_data)
    {
        insertNodeHelper(&m_rootNode, std::move(a_data));
    }

    void insertNode(const NODETYPE& a_data)
    {
        insertNodeHelper(&m_rootNode, a_data);
    }

    void preOrderTraversal() const
    {
        preOrderHelper(m_rootNode);
    }

    void inOrderTraversal() const
    {
        inOrderHelper(m_rootNode);
    }

    void postOrderTraversal() const
    {
        postOrderHelper(m_rootNode);
    }

    /* 
     * Function: removeNode
     * --------------------
     * Function remove node from the tree.
     * TODO: remove duplicates
     */

    bool remove(const NODETYPE& a_data)
    {
        TreeNode<NODETYPE>* parentRemoveNode = findParentNode(a_data);
        TreeNode<NODETYPE>* removeNode = findNodeHelper(parentRemoveNode, a_data);

        // without match
        if (removeNode == nullptr)
            return false;

        // node to remove without children
        if (isLeafNode(removeNode))
        {
            TreeNode<NODETYPE>* tmpRemoveNode = removeNode;
            deleteNodeHelper(&tmpRemoveNode);
            _setChildNode(parentRemoveNode, removeNode, nullptr);

            return true;
        }

        TreeNode<NODETYPE>* tmpRemoveNode = removeNode;
        TreeNode<NODETYPE>* replaceNode = nullptr;

        // node to remove with only one child
        if (removeNode->m_leftNode && isLeafNode(removeNode->m_leftNode))
        {
            replaceNode = removeNode->m_leftNode;
            replaceNode->m_leftNode = nullptr;
            replaceNode->m_rightNode = removeNode->m_rightNode;

            _setChildNode(parentRemoveNode, tmpRemoveNode, replaceNode);
        }
        else if (removeNode->m_rightNode && isLeafNode(removeNode->m_rightNode))
        {
            replaceNode = removeNode->m_rightNode;
            replaceNode->m_leftNode = removeNode->m_leftNode;
            replaceNode->m_rightNode = nullptr;

            _setChildNode(parentRemoveNode, tmpRemoveNode, replaceNode);
            
        }
        else
        {
            /* find replacement node for node to be removed. First find the largest
             * node of the left child, otherwise find smallest node of the right child.
             */
            TreeNode<NODETYPE>* parentReplaceNode;
            parentReplaceNode = findMaxParentNode(removeNode->m_leftNode);
            replaceNode = findMaxNode(parentReplaceNode);

            if (replaceNode == nullptr)
            {
                parentReplaceNode = findMinParentNode(removeNode->m_rightNode);
                replaceNode = findMinNode(parentReplaceNode);

                // without node to replace
                if (replaceNode == nullptr)
                    return false;
            }

            TreeNode<NODETYPE>* tmpReplaceNode = replaceNode;
            TreeNode<NODETYPE>* childReplaceNode = nullptr;

            // replace node has a child, that child must be a new child of 
            // the parent of the replace node
            if (replaceNode->m_leftNode != nullptr)
                childReplaceNode = replaceNode->m_leftNode;

            // set parent of replace node with new child
            _setChildNode(parentReplaceNode, tmpReplaceNode, childReplaceNode);
            replaceNode->m_leftNode = removeNode->m_leftNode;
            replaceNode->m_rightNode = removeNode->m_rightNode;
        }

        // update parent of remove node with replacement node
        _setChildNode(parentRemoveNode, tmpRemoveNode, replaceNode);

        // root node to be removed, update new root node
        if (parentRemoveNode == removeNode)
            m_rootNode = replaceNode;

        // remove a node
        removeNode->m_leftNode = nullptr;
        removeNode->m_rightNode = nullptr;
        deleteNodeHelper(&removeNode);

        return true;
    }

    /*
     * Function: find
     * --------------
     * Find tree node.
     */

    TreeNode<NODETYPE>* find(const NODETYPE& a_data) const
    {
        return findNodeHelper(m_rootNode, a_data);
    }

protected:

    TreeNode<NODETYPE>* getRootNode()
    {
        return m_rootNode;
    }

    /*
     * Function: _setChildNode
     * -----------------------
     * Helper function to set parent old child node with new child node.
     */

    bool _setChildNode(TreeNode<NODETYPE>* a_parent,
                       TreeNode<NODETYPE>* a_oldChild,
                       TreeNode<NODETYPE>* a_newChild)
    {
        if (a_parent == nullptr) {
            return false;
        }

        if (a_oldChild == nullptr)
        {
            if ( (a_parent->m_leftNode == nullptr) &&
                 (a_parent->m_rightNode == nullptr) ) {
                return false;
            }
        }

        if (a_parent->m_leftNode == a_oldChild) {
            a_parent->m_leftNode = a_newChild;
            return true;
        }

        if (a_parent->m_rightNode == a_oldChild) {
            a_parent->m_rightNode = a_newChild;
            return true;
        }

        return false;
    }

    /*
     * Function: findParentNode
     * ------------------------
     * Helper function to find parent node.
     */

    TreeNode<NODETYPE>* findParentNode(const NODETYPE& a_data) const
    {
        return findParentNode(m_rootNode, a_data);
    }

    /* Attach node to root node.
     * Helper method modifies the pointer's data, instead of passing
     * "as a pointer" we have to pass the address of that pointer
     * that's contents is being modified. In this case we add another
     * tree node with node data. Another case we could declare
     * function parameter type as *& (reference to pointer) instead
     * of ** (pointer to pointer or shortly pptr).
     */

    void insertNodeHelper(TreeNode<NODETYPE>** a_ptr,
                          const NODETYPE&      a_data)
    {
        if (*a_ptr == nullptr) { // derefernce pptr == ptr
            // Empty tree node.
            *a_ptr = new TreeNode<NODETYPE>(a_data);
        }
        else {
            // allow duplicate insertion
            if (a_data <= (*a_ptr)->m_data) {
                insertNodeHelper( &((*a_ptr)->m_leftNode), a_data );
            }
            else {
                insertNodeHelper( &((*a_ptr)->m_rightNode), a_data );
            }
        }
    }

    void insertNodeHelper(TreeNode<NODETYPE>** a_ptr,
                          NODETYPE&&           a_data)
    {
        if (*a_ptr == nullptr) { // derefernce pptr == ptr
            // Empty tree node.
            *a_ptr = new TreeNode<NODETYPE>(a_data);
        }
        else {
            // allow duplicate insertion
            if (a_data <= (*a_ptr)->m_data) {
                insertNodeHelper( &((*a_ptr)->m_leftNode), std::move(a_data) );
            }
            else {
                insertNodeHelper( &((*a_ptr)->m_rightNode), std::move(a_data) );
            }
        }
    }

    /*
     * Function: findParentNode
     * ------------------------
     * Function search parent node.
     *
     * On success return node, otherwise nullptr.
     */

    TreeNode<NODETYPE>* findParentNode(TreeNode<NODETYPE>* a_ptr,
                                       const NODETYPE&     a_data) const
    {
        if (a_ptr == nullptr) {
            return nullptr;
        }

        if (a_data < a_ptr->m_data)
        {
            if ( (a_ptr->m_leftNode != nullptr) &&
                 (a_ptr->m_leftNode->m_data == a_data) )
            {
                // found parent
                return a_ptr;
            }

            return findParentNode(a_ptr->m_leftNode, a_data);
        }
        else if (a_data > a_ptr->m_data)
        {
            if ( (a_ptr->m_rightNode != nullptr) && 
                 (a_ptr->m_rightNode->m_data == a_data) )
            {
                // found parent
                return a_ptr;
            }

            return findParentNode(a_ptr->m_rightNode, a_data);
        }

        // parent node is the root node
        return a_ptr;
    }

    TreeNode<NODETYPE>* findNodeHelper(TreeNode<NODETYPE>* a_ptr,
                                       const NODETYPE&     a_data) const
    {
        return _findNodeHelper(a_ptr, a_data);
    }

    const TreeNode<NODETYPE>* findNodeHelper(const TreeNode<NODETYPE>* a_ptr,
                                             const NODETYPE&           a_data) const
    {
        return _findNodeHelper(a_ptr, a_data);
    }

    /*
     * Function: _findNodeHelper
     * ------------------------
     * Function search for the tree node.
     *
     * On success return node, otherwise nullptr.
     */

    template<typename TREENODE>
    TREENODE* _findNodeHelper(TREENODE* a_ptr, const NODETYPE& a_data) const
    {
        if (a_ptr == nullptr)
            return nullptr;

        if (a_data < a_ptr->m_data) {
            return findNodeHelper( a_ptr->m_leftNode, a_data);
        }
        else if (a_data > a_ptr->m_data) {
            return findNodeHelper( a_ptr->m_rightNode, a_data);
        }
        else if (a_data == a_ptr->m_data) {
            return a_ptr;
        }

        // without result
        return nullptr;
    }

    /*
     * Function: findMinParentNode
     * ---------------------------
     * Function find parent of the smallest node.
     *
     */

    TreeNode<NODETYPE>* findMinParentNode(TreeNode<NODETYPE>* a_ptr) const
    {
        if (a_ptr == nullptr) {
            return nullptr;
        }

        if (isLeafNode(a_ptr)) {
            return a_ptr;
        }

        if (a_ptr->m_leftNode != nullptr)
        {
            if (a_ptr->m_leftNode->m_leftNode == nullptr) {
                return a_ptr;
            }

            return findMinParentNode(a_ptr->m_leftNode);
        }

        return a_ptr;
    }

    /*
     * Function: findMinNode
     * ---------------------
     * Function search for the smallest node.
     */

    TreeNode<NODETYPE>* findMinNode(TreeNode<NODETYPE>* a_ptr) const
    {
        TreeNode<NODETYPE>* node = findMinParentNode(a_ptr);

        if (node != nullptr)
        {
            if (node->m_leftNode != nullptr) {
                node = node->m_leftNode;
            }
        }

        return node;
    }

    /*
     * Function: findMaxParentNode
     * ---------------------------
     * Function search parent for the largest node.
     */

    TreeNode<NODETYPE>* findMaxParentNode(TreeNode<NODETYPE>* a_ptr) const
    {
        if (a_ptr == nullptr) {
            return nullptr;
        }

        if (isLeafNode(a_ptr)) {
            return a_ptr;
        }
 
        if (a_ptr->m_rightNode != nullptr)
        {
            if (a_ptr->m_rightNode->m_rightNode == nullptr) {
                // found parent
                return a_ptr;
            }

            return findMaxParentNode(a_ptr->m_rightNode);
        }

        return a_ptr;
    }

    /*
     * Function: findMaxNode
     * ---------------------
     * Function search for the largest node.
     */

    TreeNode<NODETYPE>* findMaxNode(TreeNode<NODETYPE>* a_ptr) const
    {
        TreeNode<NODETYPE>* node = findMaxParentNode(a_ptr);

        if (node != nullptr)
        {
            if (node->m_rightNode != nullptr) {
                node = node->m_rightNode;
            }
        }

        return node;
    }

    // Recursively delete nodes in postorder traversal of Tree
    void deleteNodeHelper(TreeNode<NODETYPE>** a_ptr)
    {
        if ((a_ptr != nullptr) && (*a_ptr != nullptr))
        {
            deleteNodeHelper( &((*a_ptr)->m_leftNode) );
            deleteNodeHelper( &((*a_ptr)->m_rightNode) );

            delete *a_ptr;
            *a_ptr = nullptr;
            a_ptr = nullptr;
        }
    }

    // Preorder processing tree nodes without tree modifications
    void preOrderHelper(TreeNode<NODETYPE>* a_ptr) const
    {
        if (a_ptr != nullptr) {
            std::cout << a_ptr->m_data << ' ';
            preOrderHelper(a_ptr->m_leftNode);
            preOrderHelper(a_ptr->m_rightNode);
        }
    }

    // Inorder processing tree nodes without tree modifications
    void inOrderHelper(TreeNode<NODETYPE>* a_ptr) const
    {
        if (a_ptr != nullptr) {
            inOrderHelper(a_ptr->m_leftNode);
            std::cout << a_ptr->m_data << ' ';
            inOrderHelper(a_ptr->m_rightNode);
        }
    }

    // Postorder processing tree nodes without tree modifications
    void postOrderHelper(TreeNode<NODETYPE>* a_ptr) const
    {
        if (a_ptr != nullptr) {
            postOrderHelper(a_ptr->m_leftNode);
            postOrderHelper(a_ptr->m_rightNode);
            std::cout << a_ptr->m_data << ' ';
        }
    }
};

#endif
