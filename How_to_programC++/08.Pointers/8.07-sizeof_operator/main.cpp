// main.cpp
// Determine size of fundamental types.
#include <iostream>
using std::size_t;
using std::cout; // iostream
using std::endl;

int main()
{
	char c; // variable of type char
	short s; // variable of type short
	int i; // variable of type int
	size_t st; // variable of type size_t
	long l; // variable of type long
	float f; // variable of type float
	double d; // variable of type double
	long double ld; // variable of type long double
	int array[20]; // array of int
	int* nPtr = array; // pointer to array, variable of int

	cout << "\nsizeof c: " << sizeof c
		<< "\tsizeof(char): " << sizeof (char)
		<< "\nsizeof s: " << sizeof s
		<< "\tsizeof(short): " << sizeof (short)
		<< "\nsizeof i: " << sizeof i
		<< "\tsizeof(int): " << sizeof (int)
		<< "\nsizeof st: " << sizeof st
		<< "\tsizeof(size_t): " << sizeof (size_t)
		<< "\nsizeof l: " << sizeof l
		<< "\tsizeof(long): " << sizeof (long)
		<< "\nsizeof f: " << sizeof f
		<< "\tsizeof(float): " << sizeof (float)
		<< "\nsizeof d: " << sizeof d
		<< "\tsizeof(double): " << sizeof (double)
		<< "\nsizeof ld: " << sizeof ld
		<< "\tsizeof(long double): " << sizeof (long double)
		<< "\nsizeof array: " << sizeof array
		<< "\nsizeof nPtr: " << sizeof nPtr << endl;

	return 0;	
}
