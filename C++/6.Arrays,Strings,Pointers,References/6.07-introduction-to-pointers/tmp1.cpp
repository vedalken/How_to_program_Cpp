// tmp1.cpp
#include <iostream>
int main()
{
	int value = 5;
	int* ptr1 = &value;

	std::cout << value << std::endl;
	std::cout << *ptr1 << std::endl;
	return 0;
}
