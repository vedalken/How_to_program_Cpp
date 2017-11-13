#include <iostream>  // cout, endl
#include <array>     // array
#include <algorithm> // copy
#include <iterator>  // ostream_iterator
#include <numeric>   // accumulate

// binary function adds square of its second argument and the
// running total in its first argument, then return the sum
int sumSquares(int total, int value)
{
	return total + value * value;
}

// Template class defines overloaded operator() that adds
// the square  of its second argument and running total
// in its first argument, then return sum
template <typename T>
class SumSquares
{
public:
	// add square of value to total and return result
	T operator()(const T& a_total, const T& a_value) {
		return a_total + a_value * a_value;
	}
};

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> integers = {1,2,3,4,5,6,7,8,9,10};
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "array integers contains: ";
	std::copy (integers.cbegin(), integers.cend(), output);

	// calculate sum of square of elements of array integers
	// using binary function sumOfSquares
	int result = std::accumulate (integers.cbegin(), integers.cend(),
				      0, &sumSquares);
	std::cout << "\n\nSum of squares of elements in integers using "
		  << "binary\nfunction sumSquares: " << result;

	// calculate sum of square of elements of array integers
	// using binary function object of type SumSquares<int>()
	// In the function is called anonymous default class constructor
	// with access to the function object
	result = std::accumulate (integers.cbegin(), integers.cend(),
			          0, SumSquares<int>());
	std::cout << "\n\nSum of squares of elements in integers using "
		  << "binary\nfunction object of type " 
		  << "SumSquares<int>: " << result << std::endl;

	return 0;
}
