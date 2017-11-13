#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

bool greater9(int);

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> init{10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
	std::ostream_iterator<int> output(std::cout, " ");

	/**
	 * Test std::replace
	 */
	std::array<int, SIZE> a1(init);
	std::cout << "a1 before replacing all 10s with 100s:\n";
	std::copy (a1.cbegin(), a1.cend(), output);

	std::replace (a1.begin(), a1.end(), 10, 100);
	std::cout << "\na1 after replacing all 10s with 100s:\n";
	std::copy (a1.cbegin(), a1.cend(), output);

	/**
	 * Test std::replace_copy
	 */
	std::array<int, SIZE> a2(init);
	std::array<int, SIZE> c;
	std::cout << "\n\na2 before replacing all 10s with 100s and copying:\n";
	std::copy (a2.cbegin(), a2.cend(), output);

	std::replace_copy (a2.cbegin(), a2.cend(),
			   c.begin(), 10, 100);
	std::cout << "\nc after replacing all 10s with 100s and copying:\n";
	std::copy (c.cbegin(), c.cend(), output);

	/**
	 * Test std::replace_if
	 */
	std::array<int, SIZE> a3(init);
	std::cout << "\n\na3 before replacing numbers greater than 9 with 100:\n";
	std::copy (a3.cbegin(), a3.cend(), output);

	std::replace_if (a3.begin(), a3.end(), greater9, 100);
	std::cout << "\na3 after replacing number greaters than 9 with 100:\n";
	std::copy (a3.cbegin(), a3.cend(), output);

	/**
	 * Test std::replace_copy_if
	 */
	std::array<int, SIZE> a4(init);
	std::array<int, SIZE> c2;
	std::cout << "\n\na4 before replacing numbers greater than 9 "
		"with 100s and copying:\n";
	std::copy (a4.cbegin(), a4.cend(), output);

	std::replace_copy_if (a4.cbegin(), a4.cend(), 
			      c2.begin(),
			      greater9, 100);
	std::cout << "\n\nc2 before replacing numbers greater than 9 "
		"with 100s and copying:\n";
	std::copy (c2.cbegin(), c2.cend(), output);

	std::cout << std::endl;
	return 0;
}

bool greater9(int i)
{
	return i > 9;
}
