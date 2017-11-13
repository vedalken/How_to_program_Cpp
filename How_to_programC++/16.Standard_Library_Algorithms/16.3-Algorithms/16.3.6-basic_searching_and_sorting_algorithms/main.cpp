#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

// predicate function
bool greater10(int value)
{
	return value > 10;
}

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> a = {10, 2, 17, 5, 16, 8, 13, 11, 20, 7};
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "Array contains: ";
	std::copy (a.cbegin(), a.cend(), output);

	// locate first occurance of 16 in a
	auto location = std::find (a.cbegin(), a.cend(), 16);

	if ( location != a.cend() ) {
		std::cout << "\n\nFound 16 at location " << (location - a.cbegin());
	}
	else {
		std::cout << "\n\n16 not found.";
	}

	// locate first occurance of 100 in a
	location = std::find (a.cbegin(), a.cend(), 100);

	if ( location != a.cend() ) {
		std::cout << "\n\nFound 100 at location " << (location - a.cbegin());
	}
	else {
		std::cout << "\n\n100 not found.";
	}

	// locate first occurance of value greater than 10 in a
	location = std::find_if (a.cbegin(), a.cend(), greater10);

	if ( location != a.cend() ) {
		std::cout << "\n\nThe first value greater than 10 is " << *location 
			<< "\nfound at location " << (location - a.cbegin());
	}
	else {
		std::cout << "\n\nNo values greater than 10 were found.";
	}

	// sort values in ascending order
	std::sort (a.begin(), a.end());
	
	std::cout << "\n\narray a after sort: ";
	std::copy (a.cbegin(), a.cend(), output);

	// use binary_search to locate 13 in a
	if ( std::binary_search(a.cbegin(), a.cend(), 13) ) {
		std::cout << "\n\n13 was found in a";
	}
	else {
		std::cout << "\n\n13 was not found in a";
	}

	// use binary_search to locate 100 in a
	if ( std::binary_search(a.cbegin(), a.cend(), 100) ) {
		std::cout << "\n\n100 was found in a";
	}
	else {
		std::cout << "\n\n100 was not found in a";
	}
	

	// determine whether all of the lements of a are greater than 10
	if ( std::all_of (a.cbegin(), a.cend(), greater10) ) {
		std::cout << "\n\nAll elements in a are greater than 10";
	}
	else {
		std::cout << "\n\nSome elements in a are not greater than 10";
	}

	// determine whether any of the elements of a are greater than 10
	if ( std::any_of (a.cbegin(), a.cend(), greater10) ) {
		std::cout << "\n\nSome elements in a are greater than 10";
	}
	else {
		std::cout << "\n\nNone of the elements in a are greater than 10";
	}
	
	// determine whether none of elements of a are greater than 10
	if ( std::none_of (a.cbegin(), a.cend(), greater10) ) {
		std::cout << "\n\nNone of the elements in a are greater than 10";
	}
	else {
		std::cout << "\n\nSome elements in a are greater than 10";
	}

	// locate first occurance of value that is not greater than 10 in a
	location = std::find_if_not (a.cbegin(), a.cend(), greater10);

	if ( location != a.cend() ) {
		std::cout << "\n\nThe first value not greater than 10 is " << *location 
			<< "\nfound at location " << (location - a.cbegin());
	}
	else {
		std::cout << "\n\nOnly values greater than 10 were found.";	
	}

	std::cout << std::endl;

	return 0;
}
