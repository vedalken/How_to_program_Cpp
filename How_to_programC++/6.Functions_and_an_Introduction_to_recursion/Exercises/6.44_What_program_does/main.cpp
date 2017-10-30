// main.cpp
// What is wrong with program?
#include <iostream>
#include <cstdio> // wrong: must include cstdio library
using namespace std;

int main()
{
	int c;

	if ( (c = cin.get()) != EOF ) 
	{
		main();
		cout << c << endl;
	}

	return 0;	
}
