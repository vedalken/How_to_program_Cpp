#include <iostream>
#include "stack.h"

int main()
{
	Stack<double> doubleStack;        // stack of double
	const size_t doubleStackSize = 5; // stack of double size
	double doubleValue = 1.1;

	std::cout << "Pushing elements onto doubleStack:\n";

	// adding elements to stack
	for (size_t i = 0; i < doubleStackSize; ++i)
	{
		doubleStack.push(doubleValue);
		std::cout << doubleValue << ' ';
		doubleValue += 1.1;
	}

	std::cout << "\n\nPopping elements from doubleStack\n";

	// remove elements from stack
	while (!doubleStack.empty())
	{
		std::cout << doubleStack.top() << ' ';
		doubleStack.pop();
	}

	std::cout << "\nStack is empty, cannot pop.\n";

	Stack<int> intStack;
	const size_t intStackSize = 10;
	int intValue = 1;

	std::cout << "\n\nPushing element onto intStack:\n";

	for (size_t i = 0; i < intStackSize; ++i)
	{
		intStack.push(intValue);
		std::cout << intValue << ' ';
		++intValue;
	}

	std::cout << "\n\nPopping elements from intStack\n";

	while (!intStack.empty())
	{
		std::cout << intStack.top() << ' ';
		intStack.pop();
	}

	std::cout << "\nStack is empty, connot pop." << std::endl;

	return 0;
}
