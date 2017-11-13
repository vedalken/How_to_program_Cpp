#include <iostream>
#include <iterator>
#include <algorithm>
#include <array>
#include <numeric>

bool greater9(int);
void outputSquare(int);
int cube(int);

int main()
{
	const size_t SIZE = 10;
	std::ostream_iterator<int> output(std::cout, " ");
	std::array<int, SIZE> a1;
	std::iota (a1.begin(), a1.end(), 1); /* insert in array elem. from 1 to 10 */

	std::cout << "\na1 before random shuffle:\n";
	std::copy( a1.cbegin(), a1.cend(), output );

	// random shuffle elements
	std::random_shuffle( a1.begin(), a1.end() );
	std::cout << "\na1 after random shuffle:\n";
	std::copy( a1.cbegin(), a1.cend(), output );

	std::array<int, SIZE> a2 = {100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
	std::cout << "\n\na2 contains: ";
	std::copy (a2.cbegin(), a2.cend(), output);

	/* count number of elements in a2 with value 8 */
	int result = std::count (a2.cbegin(), a2.cend(), 8);
	std::cout << "\nNumber of elements matching 8: " << result;

	/* count number of elements in a2 greater than 9 */
	result = std::count_if (a2.cbegin(), a2.cend(), &greater9);

	/* locate minumum element in a2 */
	std::cout << "\n\nMinimum element in a2 is "
		<< *std::min_element (a2.cbegin(), a2.cend());

	/* locate maximum element in a2 */
	std::cout << "\nMaximum element in a2 is "
		<< *std::max_element (a2.cbegin(), a2.cend());

	/* locate minimum and maximum elements in a2 */
	std::pair<std::array<int, SIZE>::const_iterator, // or use auto keyword
		  std::array<int, SIZE>::const_iterator> 
	    minMax = std::minmax_element (a2.cbegin(), a2.cend());
	std::cout << "\nThe minimum and maximum elements in a2 are "
		<< *(minMax.first) << " and " << *(minMax.second)
		<< ", respectively.";

	/* calculate sum of elements in a1 */
	std::cout << "\n\nThe total sum of elements in a1 is "
		<< std::accumulate (a1.cbegin(), a1.cend(), 0);

	/* calculate square of the elements in a1 and output them */
	std::cout << "\n\nThe square of every integer in a1 is:\n";
	std::for_each (a1.cbegin(), a1.cend(), outputSquare);

	/* calculate cube of each element in a1 */
	std::array<int, SIZE> cubes;
	std::transform (a1.cbegin(), a1.cend(), cubes.begin(), cube);
	
	std::cout << "\n\nThe cube of every integer in a1 is:\n";
	std::copy (cubes.cbegin(), cubes.cend(), output);
	std::cout << std::endl;

	return 0;
}

bool greater9(int value)
{
	return value > 9;
}

void outputSquare(int value)
{
	std::cout << value * value << ' ';
}

int cube(int value)
{
	return value*value*value;
}
