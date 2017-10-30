// passbyval.cpp
// Program calculates cube of an integer using
// function pass-by-value.
#include <iostream>
int cubeByValue( int );

int main()
{
	int number = 5; // initialize variable
	std::cout << "Original value: " << number;
	
	// assign function return value to the variable number
	number = cubeByValue( number );
	std::cout << "\nThe new value of number is: " << number << std::endl;

	return 0;	
}

int cubeByValue( int n ) {
	return n * n * n;
}
