#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include "tree.h"

/*
 * Function: depth
 * ---------------
 * Function recursively determine tree depth.
 */

template<typename NODETYPE>
int depth(const TreeNode<NODETYPE>* a_treeNode)
{
    if (a_treeNode == nullptr) {
        // tree depth level starts with root children. That means
        // root node is at depth 0.
        return -1;
    }

    // left and right tree depth
    int dleft = depth(a_treeNode->getLeftNode());
    int dright = depth(a_treeNode->getRightNode());

    if (dleft >= dright) {
        return ++dleft;
    }
    return ++dright;
}

/*
 * Function: depth
 * ---------------
 * Function determine tree depth.
 */

template<typename NODETYPE>
int depth(const Tree<NODETYPE>& a_tree)
{
    return depth(a_tree.getRootNode());
}

#endif
