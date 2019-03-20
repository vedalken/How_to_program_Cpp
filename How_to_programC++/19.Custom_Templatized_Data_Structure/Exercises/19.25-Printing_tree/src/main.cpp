#include <iostream>
#include <vector>
#include "tree.h"

int main()
{
    Tree<int> intTree;

    std::vector<int> v = {49, 83, 28, 97, 71, 28, 40, 18, 
                          99, 92, 11, 19, 32, 40, 44, 69, 72};
    for (auto i : v) {
        intTree.insertNode(i);
    }

    // show binary tree
    intTree.outputTree(5);

    return 0;
}
