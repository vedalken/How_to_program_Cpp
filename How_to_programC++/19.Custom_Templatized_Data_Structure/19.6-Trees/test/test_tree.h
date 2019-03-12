#ifndef TEST_TREE_H
#define TEST_TREE_H

#include "tree.h"

template<typename NODETYPE>
class TestTree : public Tree<NODETYPE>
{
public:
    TestTree() : Tree<NODETYPE>()
    {
    }

    void deleteNodeHelper(TreeNode<NODETYPE>** a_ptr)
    {
        return Tree<NODETYPE>::deleteNodeHelper(a_ptr);
    }

    TreeNode<NODETYPE>* getRootNode()
    {
        return Tree<NODETYPE>::getRootNode();
    }

    TreeNode<NODETYPE>* findParentNode(const NODETYPE& a_data)
    {
        return findParentNode(Tree<NODETYPE>::getRootNode(), a_data);
    }

    TreeNode<NODETYPE>* findParentNode(TreeNode<NODETYPE>* a_ptr,
                                       const NODETYPE&     a_data)
    {
        return Tree<NODETYPE>::findParentNode(a_ptr, a_data);
    }

    TreeNode<NODETYPE>* findNodeHelper(TreeNode<NODETYPE>* a_ptr,
                                       const NODETYPE&     a_data)
    {
        return Tree<NODETYPE>::findNodeHelper(a_ptr, a_data);
    }

    const TreeNode<NODETYPE>* findNodeHelper(const TreeNode<NODETYPE>* a_ptr,
                                             const NODETYPE&           a_data)
    {
        return Tree<NODETYPE>::findNodeHelper(a_ptr, a_data);
    }

};

#endif
