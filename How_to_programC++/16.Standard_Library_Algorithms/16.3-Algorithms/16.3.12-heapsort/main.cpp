#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

int main()
{
	const size_t SIZE = 10;
	std::array<int, SIZE> init = {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
	std::array<int, SIZE> a(init);
	std::ostream_iterator<int> output(std::cout, " ");

	std::cout << "Array a before make_heap:\n";
	std::copy (a.cbegin(), a.cend(), output);

	// create heap array
	std::make_heap (a.begin(), a.end());
	std::cout << "\nArray a after make_heap:\n";
	std::copy (a.cbegin(), a.cend(), output);

	if (std::is_heap(a.cbegin(), a.cend()))
		std::cout << "\nArray a forms a heap!";

	// sort elements in heap
	std::sort_heap (a.begin(), a.end());
	std::cout << "\nArray a after sort_heap:\n";
	std::copy (a.cbegin(), a.cend(), output);

	std::cout << "\n\nArray init contains:\n";
	std::copy (init.cbegin(), init.cend(), output);
	std::cout << std::endl;

	std::vector<int> v;

	// place elements of array init into v maintain elements of v in heap
	for (size_t i = 0; i < SIZE; ++i)
	{
		v.push_back( init.at(i) );
		std::push_heap( v.begin(), v.end() );
		std::cout << "\nv after push_heap( init[" << i << "] ): ";
		std::copy (v.cbegin(), v.cend(), output);
	}
	std::cout << std::endl;

	// remove elements from vector in sorted order
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << "\nv after " << v.at(i) << " popped from heap\n";
		std::pop_heap (v.begin(), v.end() - i);
		std::copy (v.cbegin(), v.cend(), output);
	}
	std::cout << std::endl;

	return 0;
}
