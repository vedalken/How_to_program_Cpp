#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

char nextLetter();

int main()
{
	const size_t SIZE = 10;

	std::array<char, SIZE>  chars;
	std::ostream_iterator<char> output(std::cout, " ");
	
	// fill array with fives ('5')
	std::fill( chars.begin(), chars.end(), '5' );
	
	std::cout << "After filling with 5s:\n";
	std::copy( chars.cbegin(), chars.cend(), output );

	// fill five elements of chars with As
	std::fill_n( chars.begin(), 5, 'A' );

	std::cout << "\n\nAfter filling first five elements with As:\n";
	std::copy( chars.cbegin(), chars.cend(), output );

	// generate values with method generator
	std::generate( chars.begin(), chars.end(), nextLetter );

	std::cout << "\n\nAfter generating alphabetic chars starting from A:\n";
	std::copy( chars.cbegin(), chars.cend(), output );

	// generate values for first five elements
	std::generate_n( chars.begin(), 5, nextLetter );

	std::cout << "\n\nAfter generating next alphabetic chars for the first five:\n";
	std::copy( chars.cbegin(), chars.cend(), output );

	std::cout << std::endl;
	return 0;
}

char nextLetter()
{
	static char letter = 'A';
	return letter++;
}
