#include <iostream>  // cout, endl
#include <string>    // string
#include <iterator>  // back_inserter
#include <algorithm> // reverse_copy

bool palindromTester(const std::string& a_string);

int main(int argc, char* argv[])
{
	auto usage = [&argv]() {
		std::cout << "Usage:\n  " 
			<< argv[0] << " <string>\n\n";
	};

	// parse input arguments
	if (argc == 1) {
		usage();
		return 1;
	}
	// parse non trivial arguments
	std::string str;
	for (int a = 1; a < argc; ++a) {
		for (char* s = argv[a]; *s != '\0'; ++s) {
	    		str.push_back(*s);
		}
		if (a != (argc - 1)) {
			// add separator
			str.push_back(' ');
		}
	}

	bool ret = palindromTester(str);

	std::cout << str << " is" << (ret ? "" : " not") 
		<< " palindrom." << std::endl;

	return 0;
}

// function test string for palindrom
bool palindromTester(const std::string& a_string)
{
	std::string reversed;

	// reverse copy string into buffer
	std::reverse_copy (a_string.cbegin(), a_string.cend(),
		           std::back_inserter(reversed));

	return (reversed == a_string);
}
