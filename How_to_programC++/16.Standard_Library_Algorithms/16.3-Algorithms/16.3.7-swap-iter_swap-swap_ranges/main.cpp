#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <numeric>

int main()
{
	const size_t SIZE = 10;
	std::ostream_iterator<int> output(std::cout, " ");
	std::array<int, SIZE> a;
	std::iota (a.begin(), a.end(), 1);

	std::cout << "Array contains:\n";
	std::copy (a.cbegin(), a.cend(), output);

	/* Swap elements at locations 0 and 1 */
	std::swap (a.at(0), a.at(1));
	
	std::cout << "\n\nArray a after swapping a[0] and a[1]:\n";
	std::copy (a.cbegin(), a.cend(), output);

	/* Use iterators to swap elements at locations 0 and 1 */
	std::iter_swap (a.begin(), a.begin() + 1);
	
	std::cout << "\n\nArray a after swapping a[0] and a[1] using iter_swap:\n";
	std::copy (a.cbegin(), a.cend(), output);

	/* Swap elements in first five elements of array a with */
	/* elements in last five elements of array a */
	std::swap_ranges (a.begin(), a.begin() + 5, a.end() - 5);
	
	std::cout << "\n\nArray a after swapping the first five elements\n"
		  << "with the last five elements:\n";
	std::copy (a.cbegin(), a.cend(), output);
	std::cout << std::endl;

	return 0;
}
