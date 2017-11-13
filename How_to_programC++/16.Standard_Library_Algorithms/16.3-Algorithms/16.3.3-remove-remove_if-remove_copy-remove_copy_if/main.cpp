#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

int greater9(int i)
{
	return i > 9;
}

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> init = {
		10, 2, 10, 4, 16, 6, 14, 8, 12, 10 };
	std::ostream_iterator<int> output(std::cout, " ");

	/** 
	 * Test std::remove
	 */
	std::array<int, SIZE> a1(init);
	std::cout << "a1 before removing all 10s:\n";
	std::copy( a1.cbegin(), a1.cend(), output );

	// remove all 10s
	std::array<int, SIZE>::const_iterator newEnd;
	newEnd = std::remove( a1.begin(), a1.end(), 10 );
	std::cout << "\nafter removing all 10s:\n";
	std::copy( a1.cbegin(), newEnd, output );

	/** 
	 * Test std::remove_copy 
	 */
	std::array<int, SIZE> a2(init);
	std::array<int, SIZE> c{ 0 };
	std::cout << "\n\na2 before removing all 10s and copying:\n";
	std::copy( a2.cbegin(), a2.cend(), output );

	std::remove_copy( a2.cbegin(), a2.cend(), c.begin(), 10 );
	std::cout << "\nc after removing all 10s:\n";
	std::copy( c.cbegin(), c.cend(), output );

	/**
	 * Test std::remove_if
	 */
	std::array<int, SIZE> a3(init);
	std::cout << "\n\na3 before removing all elements greater than 9:\n";
	std::copy( a3.cbegin(), a3.cend(), output );

	newEnd = std::remove_if( a3.begin(), a3.end(), greater9 );
	std::cout << "\na3 after removing all elements greater than 9:\n";
	std::copy( a3.cbegin(), newEnd, output );

	/**
	 * Test std::remove_copy_if
	 */
	std::array<int, SIZE> a4(init);
	std::array<int, SIZE> c2{ 0 };
	std::cout << "\n\na4 before removing all elements greater "
		"than 9 and copying:\n";
	std::copy( a4.cbegin(), a4.cend(), output );

	std::remove_copy_if( a4.cbegin(), a4.cend(), c2.begin(), greater9 );
	std::cout << "\nc2 after removing all elements greater than 9 and copying:\n";
	std::copy( c2.cbegin(), c2.cend(), output );
	
	std::cout << std::endl;

	return 0;
}
