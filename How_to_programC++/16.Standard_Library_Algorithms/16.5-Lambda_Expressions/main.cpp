#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

int main()
{
	const size_t SIZE = 4;
	std::array<int, SIZE> values = {1,2,3,4};

	std::cout << "Array of values: ";
	std::copy (values.cbegin(), values.cend(),
		   std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\nArray of doubled values: ";
	// output each element multiplied by two
	std::for_each (values.cbegin(), values.cend(),
		      [](int i) {
		          std::cout << i*2 << ' ';
		      });

	long sum = 0;
	// sum all elements
	std::for_each (values.cbegin(), values.cend(),
		       [&sum](int i) -> void {
		           sum += i;
		       });

	std::cout << "\nSum of values is " << sum << std::endl;

	return 0;
}
