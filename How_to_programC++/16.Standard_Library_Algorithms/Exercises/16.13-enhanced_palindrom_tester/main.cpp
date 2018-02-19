#include <iostream>  // cout, endl
#include <string>    // string
#include <iterator>  // back_inserter
#include <algorithm> // reverse_copy
#include <cctype>    // tolower

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
	std::string original, reversed;

	// punctuation list
	std::string punc(".,!;:()");

	// reverse copy string into buffer
	std::copy_if (a_string.cbegin(), a_string.cend(),
		      std::back_inserter(original),
		      [&punc](char a_char) {
		          // copy only non-punctuation characters
		          return (punc.find(a_char) == std::string::npos);
		      });

	// convert to lower case
	std::transform (original.begin(), original.end(), original.begin(),
			[](char a_char) {
			    return std::tolower(a_char);
			});

	// reverse original string
	std::reverse_copy (original.cbegin(), original.cend(),
			   std::back_inserter(reversed));

	// test palindrom
	return (reversed == original);
}
