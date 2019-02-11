#include <iostream>
#include "list.h"

template <typename NODETYPE>
void printListBackward(const ListNode<NODETYPE>* a_listNode)
{
    if (a_listNode == nullptr)
        return;

    printListBackward(a_listNode->nextNode());
    std::cout << a_listNode->getData() << ' ';
}

template<typename NODETYPE>
void printListBackward(const List<NODETYPE>& a_list)
{
    printListBackward(a_list.firstNode());
}

int main()
{
    List<int> intList;
    for (size_t i = 10; i > 0; --i)
        intList.insertFront(i);

    std::cout << "Original list: ";
    intList.print();

    std::cout << "Reversed list: ";
    printListBackward(intList);
    std::cout << std::endl;

    return 0;
}
