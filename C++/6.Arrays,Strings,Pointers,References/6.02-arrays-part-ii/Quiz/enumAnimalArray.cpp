// enumAnimalArray.cpp
// Enumerate animals, and initialize each element to
// hold the number of legs that animal has.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// enumerate some animals
	enum animals
	{ 
		CHICKEN,	// 0
		DOG,		// 1
		CAT,		// 2
		ELEPHANT,	// 3
		DUCK,		// 4
		SNAKE,		// 5
		NUMBER_OF_ANIMALS // 6
	};

	// initialize each element to the number of legs
	// that animal has
	int array[ NUMBER_OF_ANIMALS ] = { 2, 4, 4, 4, 2, 0 };
	
	// display array values
	for (int i = 0; i < NUMBER_OF_ANIMALS; ++i)
		cout << i << ": " << array[ i ] << endl;

	return 0;	
}

