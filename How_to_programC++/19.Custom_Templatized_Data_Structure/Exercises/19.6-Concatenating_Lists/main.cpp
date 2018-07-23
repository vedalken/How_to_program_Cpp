#include "list.h"
#include "list_utility.h"

int main()
{
    List<char> list1{ 'a', 'b', 'c', 'd' };
    List<char> list2{ 'e', 'f', 'g', 'h', 'i' };
    
    concatenate(list1, list2);
    list1.print();

    return 0;
}
