// main.cpp
// Display PI value with macro 
// run as: gcc -E main.cpp > main.p
// main.p contains everything preprocessor do at this stage before compiling.
//
#include <iostream>

#define PI 3.1415926 // replace every name PI in file with value 3.1415926

using std::cout;
using std::endl;

int main()
{
	cout << "PI: " << PI << endl; 	

	return 0;	
}
