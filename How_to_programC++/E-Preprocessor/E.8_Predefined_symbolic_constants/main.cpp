// main.cpp
// Six predefined symbolic constants: 
// __DATE__, __FILE__, __TIME__, __STDC__, __LINE__, __cplusplus.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::left;

int main() 
{
	cout << left << endl
		<< setw(15) << "__DATE__ " << setw(15) <<  __DATE__ 	<< endl
		<< setw(15) << "__TIME__ "	<< setw(15) << __TIME__ 	<< endl
		<< setw(15) << "__LINE__"	<< setw(15)	<< __LINE__ 	<< endl
		<< setw(15) << "__STDC__"	<< setw(15)	<< __STDC__ 	<< endl
		<< setw(15) << "__FILE__"	<< setw(15)	<< __FILE__ 	<< endl
		<< setw(15) << "__cplusplus"<< setw(15)	<< __cplusplus 	<< endl << endl;

	return 0;	
}
