// Function add two integer numbers
// and the result is printed by function WriteAnswer();
// run as: g++ -o 2_add2num 2_add2num.cpp io.cpp
#include <iostream>

// using header file to access functions declaration
#include "fun.h"		
using namespace std;

int main ()
{
	// User enter two numbers
	int n1 = ReadNumber();
	int n2 = ReadNumber();

	// result is printed
	WriteAnswer( n1, n2, n1+n2 );
	
	return 0;
}

