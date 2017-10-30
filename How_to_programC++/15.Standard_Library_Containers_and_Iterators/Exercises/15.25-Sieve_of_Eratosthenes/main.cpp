/**
 * Prime number factorization using Sieve of Eratosthenes algorithm.
 *
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Prime.h"

int main(int argc, char* argv[])
{
	/* Usage printout message */
	auto usage = [&argv]() {
		std::cout << "Usage " << argv[0] << " <number>" << std::endl;
	};
	
	size_t number;

	/* Process input arguments */	
	switch (argc) {
	case 1:
		usage();
		return 1;
	case 2:
		number = std::strtoul(argv[1], NULL, 10);
		break;
	default:
		usage();
		return 1;
	}

	try {
		std::map<size_t,size_t> primeNumbers;
		Prime prime(number);
		prime.factorization(primeNumbers);
		prime.printFactorization(primeNumbers);
	}
	catch (const std::bad_alloc& ba) {
		size_t megaBytes = number / std::pow(1024, 3);
		std::cout << "Not enought memory to allocate " << megaBytes 
		    << " MiB on heap!" << std::endl;
	}

	return 0;
}
