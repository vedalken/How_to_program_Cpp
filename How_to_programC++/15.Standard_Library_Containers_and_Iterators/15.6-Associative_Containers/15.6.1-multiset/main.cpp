#include <iostream>
#include <iterator>
#include <array>
#include <set>
#include <algorithm>

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> a = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
	std::multiset<int, std::less<int>> intMultiset;
	std::ostream_iterator<int> output( std::cout, " " );

	std::cout << "There are currently " << intMultiset.count(15)
		<< " values of 15 in the multiset.\n";

	intMultiset.insert(15);
	intMultiset.insert(15);

	std::cout << "After inserts, there are " << intMultiset.count(15)
		<< " values of 15 in the multiset.\n";

	std::multiset<int>::const_iterator result = intMultiset.find(15);
	if ( result != intMultiset.cend() )
		std::cout << "Found value 15\n";

	result = intMultiset.find(20);
	if ( result == intMultiset.cend() )
		std::cout << "Not found value 20\n";

	/* insert elements of array */
	intMultiset.insert( a.cbegin(), a.cend() );
	std::cout << "\nAfter insert, intMultiset contains:\n";
	std::copy( intMultiset.cbegin(), intMultiset.cend(), output );

	/* determine lower and upper bound */
	std::cout << "\n\nLower bound of 22: " << *(intMultiset.lower_bound(22))
		<< "\nUpper bound of 22: " << *(intMultiset.upper_bound(22));

	/* lower and upper bound in pair */
	auto p = intMultiset.equal_range(22);

	std::cout << "\n\nEqual range of 22:" 
		<< "\n  Lower bound: " << *(p.first)
		<< "\n  Upper bound: " << *(p.second)
		<< std::endl;

	return 0;
}
