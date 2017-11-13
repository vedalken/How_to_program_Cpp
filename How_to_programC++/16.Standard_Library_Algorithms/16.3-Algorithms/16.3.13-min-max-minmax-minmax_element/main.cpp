#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

int main()
{
	std::cout << "The minimum of 12 and 7 is " << std::min(12, 7);
	std::cout << "\nThe maximum of 12 and 7 is " << std::max(12, 7);
	std::cout << "\nThe minimum of 'G' and 'Z' is " << std::min('G', 'Z');
	std::cout << "\nThe maximum of 'G' and 'Z' is " << std::max('G', 'Z');

	// determine which element is the min and which is the max
	std::pair<int, int> result1;
	result1 = std::minmax(12, 7);
	std::cout << "\n\nThe minimum of 12 and 7 is: " << result1.first
		<< "\nThe maximum of 12 and 7 is: " << result1.second;

	std::array<int, 10> items = {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "\n\nArray items contains: ";
	std::copy (items.cbegin(), items.cend(), output);

	std::pair<std::array<int, 10>::const_iterator,
		  std::array<int, 10>::const_iterator> result2;
	result2 = std::minmax_element (items.cbegin(), items.cend());
	std::cout << "\n\nThe minimum element in items is: " << *(result2.first)
		<< "\nThe maximum element in items is: " << *(result2.second)
		<< std::endl;

	return 0;
}
