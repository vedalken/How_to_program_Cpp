#include <iostream>
#include <new>

int main()
{
	const size_t memBlockSize = 50000000000;
	const size_t arraySize = 100;
	double* ptr[arraySize] = {nullptr};

	try {
		for (size_t i = 0; i < arraySize; ++i)
		{
			ptr[ i ] = new double [memBlockSize];
			std::cout << i << " Allocated " << memBlockSize / (1024 * 1024)
				  << " MiB.\n";
		}
	}
	catch (const std::bad_alloc& ba) {
		std::cerr << "Exception occured: " << ba.what() << std::endl;
	}

	for (size_t i = 0; i < arraySize; ++i) {
		delete[] ptr[i];
		ptr[i] = nullptr;
	}

	return 0;
}
