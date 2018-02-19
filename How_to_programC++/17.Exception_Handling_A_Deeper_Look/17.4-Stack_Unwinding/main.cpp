//
// Programs simulates stack unwinding process due to unhandled
// throw exception within the function process chain. The main
// function handles the exception.
//

#include <iostream>
#include <stdexcept>

void function3()
{
	std::cout << "function3 throws exception runtime_error...\n";
	throw std::runtime_error("runtime_error in function3()");
}

void function2()
{
	std::cout << "function2 calls function3()\n";
	function3();
}

void function1()
{
	std::cout << "function1 calls function2()\n";
	function2();
}

int main()
{
	std::cout << "\nProgram simulates stack unwinding:\n";

	try {
		std::cout << "In the main function. The function calls function1().\n";
		function1();
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception occured: " << e.what();
		std::cout << "\nException handled in main.\n";
	}

	std::cout << "main exits successfully.\n";
	return 0;
}
