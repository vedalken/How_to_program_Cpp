#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
	std::set<double, std::less<double>> doubleSet{ 2.1, 4.2, 9.5, 2.1, 3.7 };
	std::ostream_iterator<double> output( std::cout, " " );

	std::cout << "doubleSet contain: ";
	std::copy( doubleSet.cbegin(), doubleSet.cend(), output );

	/* insert unique number and return std::pair<iterator, bool> */
	auto p = doubleSet.insert( 13.8 );

	std::cout << "\n\n" << *(p.first)
		<< (p.second ? " was" : " was not") << " inserted";

	std::cout << "\ndoubleSet contain: ";
	std::copy( doubleSet.cbegin(), doubleSet.cend(), output );

	/* insert duplicate */
	p = doubleSet.insert( 9.5 );
	
	std::cout << "\n\n" << *(p.first)
		<< (p.second ? " was" : " was not") << " inserted";

	std::cout << "\ndoubleSet contain: ";
	std::copy( doubleSet.cbegin(), doubleSet.cend(), output );
	std::cout << std::endl;

	return 0;
}
