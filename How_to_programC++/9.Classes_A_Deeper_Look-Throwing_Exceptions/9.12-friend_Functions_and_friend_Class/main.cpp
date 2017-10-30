#include <iostream>
#include "Count.h"

int main()
{
	Count counter;

	std::cout << "counter after call setX\n";
	counter.print();

	setX(counter, 5);

	std::cout << "after call setX\n";
	counter.print();

	return 0;
}
