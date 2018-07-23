#include "list.h"

int main()
{
    List<int> list1{ 1, 3, 5, 7, 9 };
    List<int> list2{ 2, 4, 6, 8, 10, 12, 14 };

    // merge list2 into list1
    list1.merge(list2);

    List<int> list3 = std::move(list1);
    List<int> list4{0, 2, 6};

    // merge list3 into list4
    list4.merge(list3);

    std::cout << "list3: " << list3 << std::endl;
    std::cout << "list4: " << list4 << std::endl;

    return 0;
}
