#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <utility>

int main()
{
	const size_t SIZE = 10;
	std::ostream_iterator<int> output(std::cout, " ");

	std::array<int, SIZE> a1 = {1,2,3,4,5,6,7,8,9,10};
	std::array<int, SIZE> a2(a1);
	std::array<int, SIZE> a3 = {1,2,3,4,1000,6,7,8,9,10};

	std::cout << "a1: ";
	std::copy( a1.cbegin(), a1.cend(), output );
	std::cout << "a2: ";
	std::copy( a2.cbegin(), a2.cend(), output );
	std::cout << "a3: ";
	std::copy( a3.cbegin(), a3.cend(), output );

	// compare a1 and a2 for equality
	bool result = std::equal( a1.cbegin(), a1.cend(), a2.cbegin() );
	std::cout << "\na1 is" << (result ? " " : " not ") << "equal to a2.\n";

	// compare a1 and a3 for equality
	result = std::equal( a1.cbegin(), a1.cend(), a3.cbegin() );
	std::cout << "\na1 is " << (result ? "" : "not") << " equal to a3.\n";

	// compiler deduction type can be used (the keyword `auto`)
	typedef std::array<int,SIZE>::const_iterator c_iter;
	std::pair<c_iter, c_iter> location = 
		std::mismatch( a1.cbegin(), a1.cend(), 
			       a3.cbegin() );
	std::cout << "\nThere is mismatch between a1 and a3 at location "
		<< (location.first - a1.cbegin()) 
		<< "\nwhere a1 contains " << *location.first << " and a3 contains " 
		<< *location.second << "\n\n";

	char c1[SIZE] = "HELLO";
	char c2[SIZE] = "BYE BYE";

	// perform lexicographical (or dictionary or alphabetical) comparison
	result = std::lexicographical_compare( std::begin(c1), std::end(c1),
		       			       std::end(c2), std::end(c2) );
	std::cout << c1 << (result ? " is less than " :
		" is greater or equal to ") << c2 << std::endl;

	return 0;
}
