/**
 * Program incorporate Sieve of Eratosthenes algorithm
 * for printing prime numbers from 2 to 1023.
 *
 */
#include <iostream>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include "Prime.h"

template <size_t N>
void setPrimes(std::bitset<N>& primes);

template <size_t N>
void getPrimes(std::bitset<N>& primes);

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

	std::bitset<1024> primes;

	// set prime numbers
	setPrimes(primes);

	// display prime numbers
	getPrimes(primes);

	try {
		Prime prime(number);
		bool p = prime.isPrime();
		if (p) {
			std::cout << "number is prime" << std::endl;
		}
	}
	catch (const std::bad_alloc& ba) {
		size_t megaBytes = number / std::pow(1024, 3);
		std::cout << "Not enought memory to allocate " << megaBytes 
		    << " MiB on heap!" << std::endl;
	}

	return 0;
}

/**
 * Calculate prime numbers
 */
template <size_t N>
void setPrimes(std::bitset<N>& primes)
{
	for (size_t i = 2; i < N; ++i) {
		for (size_t j = 2*i; j < N; j += i) {
			if (!primes.test(j)) {
				primes.flip(j);
			}
		}
	}

	// toggle prime numbers
	primes.flip();
}

/** 
 * Display prime numbers 
 */
template <size_t N>
void getPrimes(std::bitset<N>& primes)
{
	for (size_t i = 2; i < N; ++i) {
		if (primes.test(i)) {
			std::cout << i << ' ';
		}
	}

	std::cout << std::endl;
}
