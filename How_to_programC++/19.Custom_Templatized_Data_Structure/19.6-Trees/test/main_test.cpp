#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <algorithm>
#include <doctest/doctest.h>
#include "test_tree.h"

/*
 * Test case: find
 * ---------------
 * Test find tree node.
 */

TEST_CASE("find")
{
    TestTree<int> intTree;

    std::vector<int> v = {50, 75, 25, 33, 12, 88, 31, 6};
    for (auto i : v)
        intTree.insertNode(i);

    SUBCASE("all existing value")
    {
        // check all values
        for (auto val : v)
            CHECK(intTree.find(val) != nullptr);
    }

    SUBCASE("non-existing value")
    {
        CHECK(intTree.find(123456789) == nullptr);
    }

    SUBCASE("minimum value")
    {
        REQUIRE(intTree.getRootNode() != nullptr);

        const int minValue = *std::min_element(v.cbegin(), v.cend());
        const TreeNode<int>* minNode = intTree.findMinNode(intTree.getRootNode());

        REQUIRE(minNode != nullptr);
        CHECK(minNode->getData() == minValue);
    }

    SUBCASE("maximal value")
    {
        REQUIRE(intTree.getRootNode() != nullptr);

        const int maxValue = *std::max_element(v.cbegin(), v.cend());
        const TreeNode<int>* maxNode = intTree.findMaxNode(intTree.getRootNode());

        REQUIRE(maxNode != nullptr);
        CHECK(maxNode->getData() == maxValue);
    }
}

/*
 * Test case: remove
 * -----------------
 * Test remove tree node.
 */

TEST_CASE("remove")
{
    
    TestTree<int> intTree;

    std::vector<int> v = {50, 75, 25, 33, 12, 88, 67, 31, 6, 13, 16};
    for (auto i : v)
        intTree.insertNode(i);

    SUBCASE("the smallest node")
    {
        const int minVal = *std::min_element(v.cbegin(), v.cend());

        // remove last element
        CHECK(intTree.remove(minVal) == true);

        // check successful remove
        CHECK(intTree.find(minVal) == nullptr);
    }

    SUBCASE("root node")
    {
        // root node value
        const int val = intTree.getRootNode()->getData();

        CHECK(intTree.remove(val) == true);
        CHECK(intTree.find(val) == nullptr);
    }

    SUBCASE("empty tree")
    {
        TestTree<int> tree;

        const int dummyVal = 123456;
        CHECK(tree.remove(dummyVal) == false);
    }

    SUBCASE("without match")
    {
        // try remove element without match in the tree
        CHECK(intTree.remove(99999) == false);
    }

    SUBCASE("with left child")
    {
        // node to remove
        const int removeVal = 33;

        const TreeNode<int>* const removeNode = intTree.find(removeVal);
        const TreeNode<int>* child = removeNode->getLeftNode();

        // find remove node parent
        const TreeNode<int>* const pRemoveNode = intTree.findParentNode(removeVal);
        CHECK(pRemoveNode->getRightNode() == removeNode);

        // remove node only with left child
        CHECK(child != nullptr);
        CHECK(isLeafNode(child) == true);

        // remove node without right child
        CHECK(removeNode->getRightNode() == nullptr);

        // remove node from the tree
        CHECK(intTree.remove(removeVal) == true);
        CHECK(intTree.find(removeVal) == nullptr);

        // remove node child is now in position of the removed node with same parent node
        TreeNode<int>* node = intTree.findParentNode(child->getData());
        CHECK(node != nullptr);
        CHECK(node == pRemoveNode);

        // without children same as before remove node
        child = intTree.findNodeHelper(node, child->getData());
        CHECK(isLeafNode(child) == true);
    }

    SUBCASE("with replacement node with one child")
    {
        const int removeVal = 25;  // node to remove
        const int replaceVal = 16; // node to replace with
        const int val = 15;

        REQUIRE(intTree.find(val) == nullptr);

        // add additional node with parent to be replaced with the remove node
        intTree.insertNode(val);

        const TreeNode<int>* pRemoveNode = intTree.findParentNode(removeVal);
        const TreeNode<int>* removeNode = intTree.findNodeHelper(pRemoveNode, removeVal);
        const TreeNode<int>* removeLeftNode = removeNode->getLeftNode();
        const TreeNode<int>* removeRightNode = removeNode->getRightNode();

        // parent child with remove node
        CHECK(pRemoveNode->getLeftNode() == removeNode);

        // replacement child node
        const TreeNode<int>* replaceNode = intTree.findParentNode(val);
        const TreeNode<int>* pReplaceNode = intTree.findParentNode(replaceNode->getData());
        const TreeNode<int>* replaceNodeChild = intTree.findNodeHelper(replaceNode, val);
        CHECK(replaceNode->getRightNode() == nullptr);

        // check remove node succeeded
        CHECK(intTree.remove(removeVal) == true);
        CHECK(intTree.find(removeVal) == nullptr);

        // check replacement node
        CHECK(replaceNode == pRemoveNode->getLeftNode());
        CHECK(replaceNode->getLeftNode() == removeLeftNode);
        CHECK(replaceNode->getRightNode() == removeRightNode);
        CHECK(replaceNode->getData() == replaceVal);

        // check parent node of replaced node
        // replace node contained child, that child must be child of parent of replacement
        // node before the replacement
        CHECK(pReplaceNode->getRightNode() == replaceNodeChild);
        CHECK(isLeafNode(replaceNodeChild) == true);
    }
}
