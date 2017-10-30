// Program uses PRINTARRY macro to print an array of
// integeres. Macro receive the array  and the number 
// of elements in the array as arguments
#include <iostream>
#include "macrosdef.h"

using namespace std;

int main()
{
	double a[10] = {0};

	PRINTARRAY(a, 10)
	
	std::cout << "Inline function call\n";
	printArray(a, 10);

	return 0;	
}
