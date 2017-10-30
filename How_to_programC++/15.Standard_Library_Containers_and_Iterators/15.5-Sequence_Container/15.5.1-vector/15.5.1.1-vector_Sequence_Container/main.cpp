/* 
 * Introduction to standard template library - vector
 */

#include <iostream>
#include <vector>

template<typename T>
void printVector( const std::vector<T> & );

int main()
{
	const size_t SIZE = 6;
	int values[ SIZE ] = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> integers;

	std::cout << "The initial size of integers is " << integers.size()
		<< "\nThe initial capacity of integers is " << integers.capacity();

	integers.push_back(2);
	integers.push_back(3);
	integers.push_back(4);

	std::cout << "\nThe size of integers is " << integers.size()
		<< "\nThe capacity of integers is " << integers.capacity()
		<< "\nOutput build-in array using pointer notation: ";

	/* display array using pointer notation */
	for (const int *ptr = std::begin(values); ptr != std::end(values); ++ptr)
		std::cout << *ptr << ' ';

	std::cout << "\nOutput vector using iterator notation: ";
	printVector(integers);
	
	std::cout << "\nReverse vector using iterator notation: ";

	/* auto is deduced from std::vector<int>::const_reverse_iterator */
	for (auto crit = integers.crbegin(); crit != integers.crend(); ++crit)
		std::cout << *crit << ' ';

	std::cout << std::endl;
	return 0;
}

/* function template for outputting vector elements */
template<typename T>
void printVector( const std::vector<T> &a_vector )
{
	for (auto constIterator = a_vector.cbegin();
	     constIterator != a_vector.cend(); ++constIterator)
		std::cout << *constIterator << ' ';
}
