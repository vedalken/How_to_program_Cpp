// 3.cpp
// Conditional compilation with #if #endif statement
#include <iostream>
using std::cout;
using std::endl;

#if !defined(TRUE) // define TRUE=1 if not defined earlier
	#undef TRUE
	#define TRUE 1
#endif

int main()
{
	cout <<	TRUE << endl;
	return 0;
}
