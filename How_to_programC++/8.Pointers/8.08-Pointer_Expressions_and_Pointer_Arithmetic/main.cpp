#include <iostream>
int main()
{
	int a[10] = {};
	const int* a0Ptr = &a[0]; // address e.g. 3000
	const int* a2Ptr = &a[2]; // address e.g. 3000+2*4=3008
	
	long int x = a2Ptr - a0Ptr;
	std::cout << a0Ptr 
		<< "\n" << a2Ptr << std::endl;
	std::cout << x << std::endl;
	return 0;	
}
