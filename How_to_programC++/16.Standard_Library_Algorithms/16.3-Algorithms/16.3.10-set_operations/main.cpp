#include <iostream>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
	const size_t SIZE1 = 10;
	const size_t SIZE2 = 5;
	const size_t SIZE3 = 20;
	std::array<int, SIZE1> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::array<int, SIZE2> a2 = {4, 5, 6, 7, 8};
	std::array<int, SIZE2> a3 = {4, 5, 6, 11, 15};
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "\na1 contains: ";
	std::copy (a1.cbegin(), a1.cend(), output);
	std::cout << "\na2 contains: ";
	std::copy (a2.cbegin(), a2.cend(), output);
	std::cout << "\na3 contains: ";
	std::copy (a3.cbegin(), a3.cend(), output);

	// determine whether a2 is completly included in a1
	bool ret = std::includes (a1.cbegin(), a1.cend(),
			          a2.cbegin(), a2.cend());
	if (ret) std::cout << "\n\na1 includes a2";
	else     std::cout << "\n\na1 does not include a2";

	ret = std::includes (a1.cbegin(), a1.cend(),
	                     a3.cbegin(), a3.cend());
	if (ret) std::cout << "\n\na1 includes a3";
	else     std::cout << "\n\na1 does not include a3";

	std::array<int, SIZE1> difference;
	// determine elements of a1 not in a2
	auto result = std::set_difference (a1.cbegin(), a1.cend(),
			    	           a2.cbegin(), a2.cend(),
			                   difference.begin());
	std::cout << "\n\nset_difference of a1 and a2 is: ";
	std::copy (difference.begin(), result, output);

	std::array<int, SIZE1> intersection;
	// determine elements both in a1 and a2
	std::array<int, SIZE1>::iterator result2 = 
		std::set_intersection(a1.cbegin(), a1.cend(),
			       	      a2.cbegin(), a2.cend(),
			              intersection.begin());
	std::cout << "\n\nset_intersection of a1 and a1 is: ";
	std::copy (intersection.begin(), result2, output);

	std::array<int, SIZE1 + SIZE2> symmetric_difference;
	// determine elements of a1 that are not in a3 and
	// elements of a3 that are not in a1
	auto result3 = std::set_symmetric_difference(a1.cbegin(), a1.cend(),
			                             a3.cbegin(), a3.cend(),
						     symmetric_difference.begin());
	std::cout << "\n\nset_symmetric_difference of a1 and a3 is: ";
	std::copy (symmetric_difference.begin(), result3, output);

	std::array<int, SIZE3> unionSet;
	// determine union of elements in a1 and a3
	auto result4 = std::set_union (a1.cbegin(), a1.cend(),
			               a3.cbegin(), a3.cend(),
				       unionSet.begin());
	std::cout << "\n\nset_union of a1 and a3 is: ";
	std::copy (unionSet.begin(), result4, output);
	std::cout << std::endl;

	return 0;
}
