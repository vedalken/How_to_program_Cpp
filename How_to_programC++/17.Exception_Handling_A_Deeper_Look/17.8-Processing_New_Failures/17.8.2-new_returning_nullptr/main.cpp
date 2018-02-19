//
// Program hanles `new` failures using the new handler 
// function `set_new_handler`.
//
#include <iostream>
#include <new>
#include <cstdlib>

void customNewHandler()
{
	std::cerr << "customNewHandler was called" << std::endl;
	std::exit(1);
}

int main()
{
	const size_t memBlockSize = 500000000000;
	const size_t arraySize = 100;

	double* ptr[arraySize] = {nullptr};

	// set `new` throw exception handler called on
	// memory allocation failure
	std::set_new_handler(customNewHandler);

	for (size_t i = 0; i < arraySize; ++i) {
		ptr[ i ] = new double [memBlockSize];
		std::cout << "Allocate " << memBlockSize / (1024 * 1024)
			  << " MiB.\n";
	}

	for (size_t i = 0; i < arraySize; ++i) {
		delete[] ptr[i];
		ptr[i] = nullptr;
	}

	return 0;
}
