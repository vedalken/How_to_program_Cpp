#include <vector>
#include "tree_utils.h"

int main()
{
    /*
     * Data tree:
     *            50              --- depth: 0
     *          /     \
     *        /         \
     *       25          75       --- depth: 1
     *     /    \       /  \
     *    12     33   67    88    --- depth: 2
     *  /    \         \
     * 6      13        68        --- depth: 3
     *
     */
    std::vector<int> data = {50, 25, 75, 12, 33, 67, 88, 6, 13, 68};
    Tree<int> intTree;

    for (auto i : data)
        intTree.insertNode(i);

    std::cout << "Tree depth: " << depth(intTree) << std::endl;

    return 0;
}
