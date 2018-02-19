#include <iostream>
#include <exception>

void throwException()
{
	try {
		std::cout << "Function throwException() throws exception:\n\n";
		throw std::exception();
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught in throwException() function.\n";
		std::cout << "Rethrow same exception...\n";
		throw;
	}

	std::cout << "This should never be printed!\n";
}


int main()
{
	try {
		std::cout << "Main function, calls function throwException\n";
		throwException();

		std::cout << "This should never be printed!\n";
	}
	catch (const std::exception& e) {
		std::cout << "\nException handled in main.\n";
	}

	std::cout << "\nProgram continues after catch statement.\n";

	return 0;
}
