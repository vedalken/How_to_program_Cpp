/**
 * Merge two ordered list of strings into single ordered list
 * of string.
 *
 */

#include <iostream>   // cout, endl
#include <algorithm>  // sort, copy, merge
#include <string>     // string
#include <iterator>   // ostream_iterator
#include <vector>     // vector

int main()
{
	// define print string function
	auto print = [](const std::vector<std::string>& a_vec) -> void {
		std::ostream_iterator<std::string> output(std::cout, ", ");
		std::copy (a_vec.cbegin(), a_vec.cend(), output);
	};

	std::vector<std::string> string1, string2;
	string1 = { "first", "second", "third", "fifth", "sixth" };
	string2 = { "tenth", "eleventh", "twelvth", "thirtheenth" };

	std::cout << "First string: ";
	print(string1);

	std::cout << "\nSecond string: ";
	print(string2);

	// sort two strings
	std::sort (string1.begin(), string1.end(), std::less<std::string>());
	std::sort (string2.begin(), string2.end(), std::less<std::string>());

	std::cout << "\n\nFirst string sorted: ";
	print(string1);

	std::cout << "\nSecond string sorted: ";
	print(string2);

	// merge list of strings
	std::vector<std::string> result;

	// merge two sorted strings
	std::merge (string1.cbegin(), string1.cend(),
		    string2.cbegin(), string2.cend(),
		    std::back_inserter(result));

	std::cout << "\n\nMerged first and second string:\n";
	print(result);
	std::cout << std::endl;

	return 0;
}
