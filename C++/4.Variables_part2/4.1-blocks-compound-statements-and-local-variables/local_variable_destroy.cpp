// Use this program only for compiling
// and checking local variable defintions
// in scope
#include <iostream>

int main()
{
	int nValue = 5;

	{ // begin nested block
		double dValue = 4.0;	
	} // dValue destroyed here
	
	std::cout << dValue << std::endl;
	// dValue cannot be used because it was destroyed!

	return 0;
} // nValue destroyed here
