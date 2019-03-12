#include <iostream>
#include <vector>
#include "tree.h"

int main()
{
    Tree<int> intTree;

    std::vector<int> v = {50, 75, 25, 33, 12, 88, 67, 31, 6, 13, 16};
    for (auto i : v) {
        intTree.insertNode(i);
    }

    std::cout << "Preorder traversal:\n";
    intTree.preOrderTraversal();

    std::cout << "\nInorder traversal:\n";
    intTree.inOrderTraversal();
    
    std::cout << "\nPostorder traversal:\n";
    intTree.postOrderTraversal();
    std::cout << std::endl;

    if (intTree.remove(50)) {
        std::cout << "Found match to remove" << std::endl; 
    }

    std::cout << "Inorder traversal:\n";
    intTree.inOrderTraversal();

    return 0;
}
