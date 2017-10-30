#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <stdexcept>
#include <iterator>

int main()
{
	const size_t SIZE = 6;
	std::array<int, SIZE> values = {1, 2, 3, 4, 5, 6};
	std::vector<int> integers( values.cbegin(), values.cend() );
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "Vector integers contains: ";
	std::copy( integers.cbegin(), integers.cend(), output );

	std::cout << "\nFirst element of integers: " << integers.front()
		<< "\nLast element of integers: " << integers.back();

	/* set first element */
	integers[0] = 7;
	/* set third element */
	integers.at(2) = 10;

	/* insert 22 at 2nd element */
	/* previous 2nd element after insertion becomes 3rd element */
	integers.insert( integers.cbegin() + 1, 22 );

	/* contents vector after changes */
	std::cout << "\nContent of integers after changes: ";
	std::copy( integers.cbegin(), integers.cend(), output );

	/* access out-of-range element */
	try
	{
		integers.at(100) = 777;
	}
	catch ( const std::out_of_range &oor )
	{
		std::cout << "\n\nException: " << oor.what();
	}

	/* erase first element */
	integers.erase( integers.cbegin() );

	std::cout << "\nContent of integers after erasing 1st element: ";
	std::copy( integers.cbegin(), integers.cend(), output );

	/* erase remaining element */
	integers.erase( integers.cbegin(), integers.cend() );
	std::cout << "\nAfter erasing all elements, vector integers "
		<< ( integers.empty() ? "is" : "is not") << " empty";

	/* insert element from array */
	integers.insert( integers.cbegin(), values.cbegin(), values.cend() );
	std::cout << "\nContent of integers before clear: ";
	std::copy( integers.cbegin(), integers.cend(), output );

	integers.clear();
	std::cout << "\nAfter clear, vector integers "
		<< ( integers.empty() ? "is" : "is not") << " empty" << std::endl;

	return 0;
}
