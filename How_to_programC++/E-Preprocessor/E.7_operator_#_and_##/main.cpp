// main.cpp
// Macro usage, argument call by #, which cause a replacement-text token
// to be converted to a string surrounded by quotes.
#include <iostream>
using std::cout;
using std::endl;

// define macro HELLO with argument x
// operator # convert text into string, surrounded by quotes - white spaces are
// concatenated during preprocessing
#define HELLO(x)	cout << "Hello, " #x << endl

// concatenate two arguments
#define GLUE(x,y) x ## y

// concatenate two tokens with ## operator - operator must have two operands!

int main()
{
	HELLO(Milos); // replace macro at this point - done by preprocessor
	GLUE(c,out) << "test" << endl; // concatenate c and out 

	return 0;	
}
