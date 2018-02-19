#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <iterator>
#include <functional>

int main()
{
	std::ostream_iterator<int> output(std::cout, " ");

	/** 
	 *  a) fill the entire array of strings names items with "hello"
	 */
	const size_t c_size = 10;
	std::array<std::string, c_size> items;
	std::fill (items.begin(), items.end(), "hello");
	std::copy (items.cbegin(), items.cend(),
		   std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	/**
	 *  b) use generate algorithm to fill the array with ints
	 *     starting from 0
	 */
	std::array<int, c_size> integers;
	std::generate (integers.begin(), integers.end(),
		       []() -> int {
		           static int value = -1;
		           return ++value;
		       });
	std::copy (integers.cbegin(), integers.cend(), output);
	std::cout << std::endl;

	/**
	 *  c) use equal algorithm to compare two lists for equality
	 */
	const std::string string1("string1");
	const std::string string2("string2");
	bool result;
	result = std::equal (string1.cbegin(), string1.cend(),
			     string2.cbegin());
	std::cout << string1 << " and " << string2;
	if (!result) {
		std::cout << " are not equal" << std::endl;
	}
	else {
		std::cout << " are equal" << std::endl;
	}

	/**
	 *  d) use remove_if to remove from vector of strings named colors
	 *     all strings starting with "bl"
	 */
	std::vector<std::string> colors = {"blue", "red", "green", 
		                           "black", "pink"};
	auto last = std::remove_if (colors.begin(), colors.end(),
		        [](const std::string& a_color) -> bool {
			    // compare starting string name with "bl"
			    int result = a_color.compare(0, 2, "bl");
			    return (result == 0);
			});
	std::copy (colors.begin(), last,
		   std::ostream_iterator<std::string>(std::cout, " "));

	/**
	 *  e) use replace_if algorithm to replace with 0 all elements
	 *     with values greater than 100
	 */
	std::array<int, c_size> values = {100, 1, -13, 3, 123, 4954, 
		                          100, 76, 11, 64};
	std::cout << "\n\nOriginal array: ";
	std::copy (values.cbegin(), values.cend(), output);
	
	std::replace_if (values.begin(), values.end(),
			 [](int a_value) {
			     return a_value > 100;
			 }, 0);
	
	std::cout << "\nReplaced values (>100): ";
	std::copy (values.cbegin(), values.cend(), output);

	/**
	 *  f) use minmax_element algorithm to find the smallest and largest
	 *     values in array of doubles
	 */
	std::array<double, c_size> temperatures = {23, 32, -123, 94, 2000,
	                                           84, 45, 33, 110, 4};
	typedef std::array<double, c_size>::const_iterator cit;
	std::pair<cit, cit> res;
	res = std::minmax_element (temperatures.cbegin(), temperatures.cend());
	
	std::cout << "\n\nT: ";
	std::copy (temperatures.cbegin(), temperatures.cend(),
	           std::ostream_iterator<double>(std::cout, " "));
	std::cout << "\n  min T: " << *(res.first)
		  << "\n  max T: " << *(res.second);

	/**
	 *  g) use sort algorithm to sort array of strings
	 */
	std::array<std::string, c_size> col = {"red", "blue", "white", "green", "orange",
	                                       "purple", "yellow", "black", "pink", "gray"};
	std::cout << "\n\nColors: ";
	std::copy (col.cbegin(), col.cend(),
	           std::ostream_iterator<std::string>(std::cout, " "));

	// sort in descending order
	std::sort (col.begin(), col.end(), std::greater<std::string>());
	
	std::cout << "\nsorted colors: ";
	std::copy (col.cbegin(), col.cend(),
	           std::ostream_iterator<std::string>(std::cout, " "));

	/**
	 *  h) use reverse algorithm to reverse order ot the elements in the
	 *     array col
	 */
	std::cout << "\n\nColors: ";
	std::copy (col.cbegin(), col.cend(),
	           std::ostream_iterator<std::string>(std::cout, " "));

	std::reverse (col.begin(), col.end());	

	std::cout << "\nColors reversed: ";
	std::copy (col.cbegin(), col.cend(),
	           std::ostream_iterator<std::string>(std::cout, " "));

	/**
	 *  i) use merge algorithm to merge the contents of the two
	 *     sorted arrays
	 */
	std::array<int, 5> values1{1, 3, 5, 7, 9};
	std::array<int, 5> values2{0, 2, 4, 6, 8};
	std::vector<int> results;
	std::merge (values1.cbegin(), values1.cend(),
	            values2.cbegin(), values2.cend(),
		    std::back_inserter(results));
	std::cout << "\n\nMerge result: ";
	std::copy (results.cbegin(), results.cend(), output);

	/**
	 *  j) write a lambda expression that returns the square of its int
	 *     argument and assign lambda expression to variable squareInt
	 */
	// std::function<int(int)> squareInt;
	//   or
	// int (*squareInt)(int);
	auto squareInt = [](int a_value) {
		             return a_value * a_value;
	                 };
	int value = 32;
	std::cout << "\n" << value << "^2 = " << squareInt(value) << std::endl;

	return 0;
}
