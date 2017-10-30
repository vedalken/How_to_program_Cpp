#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

int main()
{
	std::deque<double> values;
	std::ostream_iterator<double> output( std::cout, " " );

	values.push_front( 2.2 );
	values.push_front( 1.1 );
	values.push_back( 3.5 );

	std::cout << "values contains: ";

	for (size_t i = 0; i < values.size(); ++i)
		std::cout << values.at(i) << ' ';

	/* remove first element */
	values.pop_front();
	std::cout << "\nAfter pop_front, values contains: ";
	std::copy( values.cbegin(), values.cend(), output );

	/* use subscript operator */
	values[ 1 ] = 7.5;
	std::cout << "\nAfter values[ 1 ] = 7.5, values contains: ";
	std::copy( values.cbegin(), values.cend(), output );

	std::cout << std::endl;
	return 0;
}
