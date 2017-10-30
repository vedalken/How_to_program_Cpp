#include <iostream>
//extern tells the compiler this variable is declared elsewhere
extern int g_nValue;

int main()
{	
	using namespace std;

	cout << g_nValue << endl;
	g_nValue = 7;	// localy redefine variable
	cout << g_nValue << endl;

	return 0;
}
