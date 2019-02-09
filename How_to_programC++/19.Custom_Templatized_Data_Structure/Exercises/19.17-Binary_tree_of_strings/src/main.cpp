#include <iostream>
#include <sstream>
#include <string>
#include "tree.h"

int main()
{
    // rather use the main argc and argv
    std::istringstream iss("l g k f z y a c b");

    std::string str;
    Tree<std::string> stringTree;
    while (iss >> str) {
        stringTree.insertNode(std::move(str));
    }

    std::cout << "\nPreorder traversal:\n";
    stringTree.preOrderTraversal();

    std::cout << "\nInorder traversal:\n";
    stringTree.inOrderTraversal();
    
    std::cout << "\nPostorder traversal:\n";
    stringTree.postOrderTraversal();
    std::cout << std::endl;

    return 0;
}
