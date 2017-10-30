// arrayEnum.cpp
// With enumeration array integer indices does
// not provide any to programmer about the meaning
// of the variable.
// Enumerate students and use them as array index.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// enumerate student names
	enum studentNames
	{
		MILOS,			// 0
		UROS, 			// 1
		JANEZ,			// 2
		MATJAZ,			// 3
		LUKA,			// 4
		MAX_STUDENTS 	// 5
	};

	// declare array
	int array[ MAX_STUDENTS ];
	array[ MILOS ] = 95;

	cout << array[ MILOS ] << endl;

	return 0;	
}
