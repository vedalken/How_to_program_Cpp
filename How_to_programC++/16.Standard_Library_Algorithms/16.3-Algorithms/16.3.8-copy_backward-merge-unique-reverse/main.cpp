#include <iostream>
#include <array>
#include <deque>
#include <algorithm>
#include <iterator>
#include <numeric>

bool isOdd(int value)
{
	return (value % 2 != 0);
}

int main()
{
	const size_t SIZE = 5;
	std::array<int, SIZE> a1 = {1, 3, 5, 7, 9};
	std::array<int, SIZE> a2 = {2, 4, 5, 7, 9};
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "Array a1 contains: ";
	std::copy (a1.cbegin(), a1.cend(), output);
	std::cout << "\nArray a2 contains: ";
	std::copy (a2.cbegin(), a2.cend(), output);

	std::array<int, SIZE> result;

	// place elements of a1 into results in reverse order
	std::copy_backward (a1.cbegin(), a1.cend(), result.end());
	
	std::cout << "\n\nAfter a1 copy_backward: ";
	std::copy (result.cbegin(), result.cend(), output);

	std::deque<int> result2;

	// merge elements of a1 and a2 into results2 in sorted order
	std::merge (a1.cbegin(), a1.cend(),
		    a2.cbegin(), a2.cend(),
		    std::back_inserter(result2));
	
	std::cout << "\n\nAfter merge of a1 and a2: ";
	std::copy (result2.cbegin(), result2.cend(), output);

	// eliminate duplicate values from result2
	auto end = std::unique (result2.begin(), result2.end());
	
	std::cout << "\n\nAfter unique result2: ";
	std::copy (result2.begin(), end, output);
	
	// reverse order of all elements in a1
	std::reverse (a1.begin(), a1.end());

	std::cout << "\n\nArray a1 after reverse: ";
	std::copy_n (a1.cbegin(), std::distance(a1.cbegin(), a1.cend()),
		     output);

	// display odd elements	
	std::cout << "\n\nArray a2 only odd elements: ";
	std::copy_if (a2.cbegin(), a2.cend(), output, isOdd);
	std::cout << std::endl;

	return 0;
}
