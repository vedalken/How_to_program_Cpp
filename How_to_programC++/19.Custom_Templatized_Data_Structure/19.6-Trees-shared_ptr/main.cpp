#include <iostream>
#include "tree.h"

int main()
{
    {
    Tree<double> intTree;
    for (int i = 0; i < 100000; ++i)
    {
	intTree.insertNode(i);
    }
	std::cout << "Done" << std::endl;
    }
    //Tree<int> intTree;

    for (;;) {
    }
    //std::cout << "Enter 10 integer values:\n";
    //for (int i = 0; i < 10; ++i)
    //{
    //    int value = 0;
    //    std::cin >> value;
    //    intTree.insertNode(value);
    //}

    //std::cout << "\nPreorder traversal:\n";
    //intTree.preOrderTraversal();

    //std::cout << "\nInorder traversal:\n";
    //intTree.inOrderTraversal();
    //
    //std::cout << "\nPostorder traversal:\n";
    //intTree.postOrderTraversal();
    //std::cout << std::endl;

    return 0;
}
