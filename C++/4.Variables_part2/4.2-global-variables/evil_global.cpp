#include <iostream>
// declare global variable
int g_nMode = 1;

void doSomething();	// function prototype

int main()
{	
	using namespace std;
	g_nMode = 1;

	doSomething();

	// Programmers expects g_nMode to be 2
	// but doSomething changed it to 0!
	// g_nMode is now 0!
	
	if (g_nMode == 1)
		cout << "No thread detected." << endl;
	else 
		cout << "Current release..." << endl;

	return 0;
}

void doSomething()
{
	g_nMode = 0;
}
