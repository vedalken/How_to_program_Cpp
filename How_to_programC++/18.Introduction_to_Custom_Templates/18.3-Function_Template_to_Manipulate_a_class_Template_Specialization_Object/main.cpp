#include <iostream>
#include <string>
#include "stack.h"


template <typename T>
void testStack(
	Stack<T>& a_stack,
	const T& a_value,
	const T& a_increment,
	size_t a_stackSize,
	const std::string& a_stackName)
{
	T value = a_value;

	std::cout << "Pushing elements onto " << a_stackName << std::endl;

	for (size_t i = 0; i < a_stackSize; ++i)
	{
		a_stack.push(value);
		std::cout << value << ' ';
		value += a_increment;
	}

	std::cout << "\n\nPopping elements from " << a_stackName << std::endl;

	// remove elements from stack
	while (!a_stack.empty())
	{
		std::cout << a_stack.top() << ' ';
		a_stack.pop();
	}

	std::cout << "\nStack is empty, cannot pop.\n";
}// end testStack

int main()
{
	Stack<double> doubleStack;
	const size_t doubleStackSize = 5;
	testStack(doubleStack, 1.1, 1.1, doubleStackSize, "doubleStack");

	Stack<int> intStack;
	const size_t intStackSize = 10;
	testStack(intStack, 1, 1, intStackSize, "intStack");

	return 0;
}
