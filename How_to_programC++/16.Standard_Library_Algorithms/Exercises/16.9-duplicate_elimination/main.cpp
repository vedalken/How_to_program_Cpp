#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

int main()
{
	/* Solution 1)
	 * 
	 * fast and generic solution
	 *
	std::vector<int> values;
	std::copy (std::istream_iterator<int>(std::cin), 
		   std::istream_iterator<int>(),
		   std::back_inserter(values));

	std::cout << "\nEntered values:\n";
	std::copy (values.cbegin(), values.cend(),
		   std::ostream_iterator<int>(std::cout, " "));

	std::sort (values.begin(), values.end());
	auto end = std::unique (values.begin(), values.end());
	std::cout << "\nUnique values:\n";
	std::copy (values.begin(), end,
		   std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	*/

	const size_t c_size = 20;
	std::array<int, c_size> values;
	std::ostream_iterator<int> output(std::cout, " ");

	// fill array with user values
	std::for_each (values.begin(), values.end(),
		       [](int& value) {
		           std::cin >> value;
		       });

	std::cout << "\nEntered values:\n";
	std::copy (values.cbegin(), values.cend(), output);

	std::vector<int> vals;
	std::sort (values.begin(), values.end());
	std::unique_copy (values.begin(), values.end(),
			  std::back_inserter(vals));

	std::cout << "\nUnique values:\n";
	std::copy (vals.cbegin(), vals.cend(), output);
	std::cout << std::endl;

	return 0;
}
