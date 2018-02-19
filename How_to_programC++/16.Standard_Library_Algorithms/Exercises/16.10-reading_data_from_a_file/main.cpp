#include <iostream> // cout, endl
#include <fstream>  // ifstream
#include <cstdlib>  // exit
#include <vector>   // vector
#include <iterator> // back_inserter
#include <numeric>  // accumulate

int main()
{
	// open the file
	std::ifstream inClientFile("data.txt", std::ios::in);

	if (!inClientFile) {
		std::cerr << "Failed to open file" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// file contents stored in vector
	std::vector<int> values;

	/* Solution 1)
	 *     Reading from input stream file, store in local variable
	 * and store into vector.
	 *
	int value = 0;
	while (inClientFile >> value) {
		values.push_back(value);
	}
	*/

	// read from input file stream and store in vector
	std::copy (std::istream_iterator<int>(inClientFile), // read file
	           std::istream_iterator<int>(),             // end-of-file
	           std::back_inserter(values));              // store read integer

	// sum read values
	long long sum(0);
	sum = std::accumulate (values.cbegin(), values.cend(), 0,
			       std::plus<int>());
	
	std::cout << "The file contains values:\n";
	std::copy (values.cbegin(), values.cend(),
	           std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\nSum: " << sum << std::endl;

	return 0;
}
