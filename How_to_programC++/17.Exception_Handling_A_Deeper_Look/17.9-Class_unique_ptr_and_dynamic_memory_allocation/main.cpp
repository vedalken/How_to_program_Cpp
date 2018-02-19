#include <iostream>
#include <memory>
#include "integer.h"

int main()
{
	std::cout << "Creating a unique_ptr object that points to an integer\n";
	std::unique_ptr<Integer> integerPtr( new Integer(7) );

	std::cout << "\nUsing unique_ptr to manipulate Integer\n";
	integerPtr->set(99);

	std::cout << "Integer after `set`: " << (*integerPtr).get()
		  << "\n\nTerminating program\n";

	return 0;
}
