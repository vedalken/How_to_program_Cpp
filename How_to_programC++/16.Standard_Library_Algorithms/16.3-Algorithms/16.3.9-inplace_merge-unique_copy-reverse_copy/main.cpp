#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> a1 = { 1, 3, 5, 7, 9, 1, 3, 5, 7, 9 };
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "array a1 contains: ";
	std::copy (a1.cbegin(), a1.cend(), output);

	// merge second half of elements starting from beginning
	std::inplace_merge (a1.begin(),
			    a1.begin() + std::distance(a1.cbegin(), a1.cend()) / 2,
			    a1.end());

	std::cout << "\n\nAfter inplace_merge, a1 contains: ";
	std::copy (a1.cbegin(), a1.cend(), output);

	std::vector<int> result;
	// copy only unique elements of a1 into result
	std::unique_copy (a1.cbegin(), a1.cend(), std::back_inserter(result));
	std::cout << "\n\nAfter unique_copy, a1 contains: ";
	std::copy (result.cbegin(), result.cend(), output);

	std::vector<int> result2;
	// copy elements of a1 into result2 in reverse order
	std::reverse_copy (a1.cbegin(), a1.cend(), std::back_inserter(result2));
	auto end = std::unique (result2.begin(), result2.end());
	std::cout << "\n\nAfter reverse_copy, a1 contains: ";
	std::copy (result2.begin(), end, output);
	std::cout << std::endl;

	return 0;
}
