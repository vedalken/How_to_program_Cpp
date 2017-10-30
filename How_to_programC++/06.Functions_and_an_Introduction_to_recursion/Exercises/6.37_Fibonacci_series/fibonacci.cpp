// fibonacci.cpp
// Compute fibonacci series nonrecursive.
// Determine largest fibonacci number that can be printed on my PC.
#include <iostream>
#include <cmath>
using std::cout; //iostream
using std::cin;
using std::endl;
using std::sqrt; //cmath
using std::pow;

// Calculate fibonacci series, nonrecursive
template <typename T> 
T fibonacci( T n )
{
	// initial two Fibonacci elements
	T previous = 0; // a0 = 0
	T current = 1;	// a1 = 1
	T nextFib = 0;	// next element
	
	// return one of the two initial coefficients
	if (n <= 0) {
		return previous;
	}
	else if (n == 1) {
		return current;
	}

	// search for n-th coefficient
	for (int i = 2; i <= n; ++i)
	{
		nextFib = previous + current;
		// swap Fib coefficient: a_(n-1) -> a_(n)
		// and a_(n) -> a_(n+1)
		previous = current;
		current = nextFib;
	}

	// Another way to calculate nth Fibonacci element
	//T fib;
	//fib = 1/sqrt(5) * 1/pow(2,n) * 
	//	 ( pow( 1+sqrt(5), n ) - pow( 1-sqrt(5), n ) );
	
	return nextFib;
}

// Determine the largest Fibonacci number that can be printed
// based on your system
int maxFibonacciNumber()
{
	int maxFibNumber; // 2^(N-1) -1 is maximal number can be printed (with int!)
	maxFibNumber = pow( 2, sizeof(int)*8-1 ) - 1;
	int fib = 0; 	// current Fibonacci number
	int i	= 0; 	// ith Fibonacci number
	
	while( fib >= 0 && fib <= maxFibNumber ) {
		fib = fibonacci( i );
		++i;
	}
	
	// fibonacci(i-1) > maxFibNumber
	// but i-2 is smaller!
	i -= 2;

	return i;
}
 
int main()
{
	cout << "Largest Fibonacci number is " << maxFibonacciNumber() << endl;
	cout << "Enter nth Fibonacci number: ";
	int number = 0;
	cin >> number;

	cout << "nth Fibonacci number: " << fibonacci( number ) << endl;

	return 0;
}
