#include <iostream>
#include <list>
#include <array>
#include <iterator>  // ostream_iterator
#include <algorithm> // copy

template<typename T>
void printList( const std::list<T> &a_list );

int main()
{
	const size_t SIZE = 4;
	std::array<int, SIZE> ints = { 1, 2, 3, 4 };
	std::list<int> values; /* create list of ints */
	std::list<int> otherValues; /* create another list of ints */

	/* insert items in values */
	values.push_front( 1 );
	values.push_front( 2 );
	values.push_back( 3 );
	values.push_back( 4 );

	std::cout << "values: ";
	printList( values );

	values.sort();
	std::cout << "\nvalues after sorting: ";
	printList( values );

	/* insert new values */
	otherValues.insert( otherValues.cbegin(), values.cbegin(), values.cend() );
	std::cout << "\notherValues after insert: ";
	printList( values );

	/* remove otherValues, insert otherValues at end into values */
	values.splice( values.cend(), otherValues );
	std::cout << "\nAfter splice, values: ";
	printList( values );

	/* sort integers */
	values.sort();
	std::cout << "\nAfter sort, values: ";
	printList( values );

	/* insert new elements */
	otherValues.insert( otherValues.cbegin(), ints.cbegin(), ints.cend() );
	otherValues.sort();
	std::cout << "\nAfter insert and sort, otherValues: ";
	printList( otherValues );

	/* insert otherValues into values in sorted order, remove otherValues */
	values.merge( otherValues );
	std::cout << "\nAfter merge:"
		  << "\n  values: ";      printList( values );
	std::cout << "\n  otherValues: "; printList( otherValues );

	values.pop_back();  /* remove element from end */
	values.pop_front(); /* remove element from front */
	std::cout << "\nAfter pop_back and pop_front:\n  values: ";
	printList( values );

	/* remove duplicate elements */
	values.unique();
	std::cout << "\nAfter unique, values: ";
	printList( values );

	/* swap elements of values and otherValues */
	values.swap( otherValues );
	std::cout << "\nAfter swap:"
		  << "\n  values: ";      printList( values );
	std::cout << "\n  otherValues: "; printList( otherValues );

	/* replace contents of values with otherValues */
	values.assign( otherValues.cbegin(), otherValues.cend() );
	std::cout << "\nAfter assign:"
		  << "\n  values: "; printList( values );

	/* remove otherValues, insert into values */
	values.merge( otherValues );
	std::cout << "\nAfter merge:"
		  << "\n  values: ";      printList( values );
	std::cout << "\n  otherValues: "; printList( otherValues );

	/* remove all element equals to 4 */
	values.remove( 4 );
	std::cout << "\nAfter remove 4s:"
		  << "\n  values: "; printList( values );
	std::cout << std::endl;

	return 0;
}

template<typename T>
void printList( const std::list<T> &a_list )
{
	if (a_list.empty())
		std::cout << "List is empty";
	else {
		std::ostream_iterator<T> output( std::cout, " " );
		std::copy( a_list.cbegin(), a_list.cend(), output );
	}
}
