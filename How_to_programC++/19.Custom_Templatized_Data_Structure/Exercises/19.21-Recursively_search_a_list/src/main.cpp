#include <iostream>
#include "list.cpp"

/* recursively search node value in a list */
template<typename NODETYPE>
const ListNode<NODETYPE>* searchList(const ListNode<NODETYPE>* a_node,
                                     const NODETYPE&           a_value)
{
    if (a_node != nullptr)
    {
        // found value
        if (a_node->getData() == a_value)
            return a_node;

        return searchList(a_node->nextNode(), a_value);
    }

    return nullptr;
}

template<typename NODETYPE>
void search(const List<NODETYPE>& a_list, const NODETYPE& a_value)
{
    std::cout << "Search for value: " << a_value << " ... ";

    const auto value = searchList(a_list.firstNode(), a_value);
    if (value == nullptr) {
        std::cout << "match was not found" << std::endl;
        return;
    }

    std::cout << "found match: " << value->getData() << std::endl;
}

int main()
{
    List<int> l = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "list: " << l << std::endl;

    // test for known list node value
    const int val = 7;
    search(l, val);

    // test for unknown list node value
    const int unknownVal = -999999;
    search(l, unknownVal);

    return 0;
}
