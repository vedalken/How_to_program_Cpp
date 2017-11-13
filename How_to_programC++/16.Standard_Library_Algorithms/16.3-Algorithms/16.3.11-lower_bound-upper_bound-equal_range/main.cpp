#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> a = {2,2,4,4,4,6,6,6,6,8};
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "\nArray a contains:\n";
	std::copy (a.cbegin(), a.cend(), output);

	// determine lower-bound insertion point for 6 in a
	std::array<int, SIZE>::const_iterator lower;
       	lower =	std::lower_bound (a.cbegin(), a.cend(), 6);
	std::cout << "\n\nLower bound of 6 is element "
		<< (lower - a.cbegin()) << " of array a.";

	// determine upper-bound insertion point for 6 in a
	std::array<int, SIZE>::const_iterator upper;
       	upper =	std::upper_bound (a.cbegin(), a.cend(), 6);
	std::cout << "\n\nUpper bound of 6 is element "
		<< (upper - a.cbegin()) << " of array a.";

	// determine lower and upper bound using equal_range
	// for 6 in a
	typedef std::array<int, SIZE>::const_iterator cit;
	std::pair<cit,cit> eq;
	eq = std::equal_range (a.cbegin(), a.cend(), 6);

	std::cout << "\n\nUsing equal_range of 6 for:"
		  << "\n  lower bound is " << (eq.first - a.cbegin())
		  << "\n  upper bound is " << (eq.second - a.cbegin());

	// determine lower-bound insertion point for 5 in a
       	lower =	std::lower_bound (a.cbegin(), a.cend(), 5);
	std::cout << "\n\nLower bound of 5 is element "
		<< (lower - a.cbegin()) << " of array a.";

	// determine upper-bound insertion point for 7 in a
       	upper =	std::upper_bound (a.cbegin(), a.cend(), 7);
	std::cout << "\n\nUpper bound of 7 is element "
		<< (upper - a.cbegin()) << " of array a.";
	
	// determine both lower and upper bound insertion point for 5
	eq = std::equal_range (a.cbegin(), a.cend(), 5);
	std::cout << "\n\nUsing equal_range of 5 for:"
		  << "\n  lower bound is " << (eq.first - a.cbegin())
		  << "\n  upper bound is " << (eq.second - a.cbegin());
	std::cout << std::endl;

	return 0;
}
