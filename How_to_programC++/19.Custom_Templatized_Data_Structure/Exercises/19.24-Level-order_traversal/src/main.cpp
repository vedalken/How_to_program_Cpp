#include <iostream>
#include <vector>
#include "tree.h"

int main()
{
    Tree<int> intTree;

    std::vector<int> v = {75, 25, 12, 88, 67, 31, 6, 13};
    for (auto i : v) {
        intTree.insertNode(i);
    }

    std::cout << "Level order traversal:\n";
    intTree.levelOrderTraversal();
    std::cout << std::endl;

    return 0;
}
