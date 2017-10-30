#include <iostream>
#include "global.h"	//copy interior of header file: "extern int g_nValue"
// run as g++ -Wall main1.cpp global.cpp -o main1

int main()
{
	using namespace std;

	cout << g_nValue << endl;
	g_nValue = 7;
	cout << g_nValue << endl;

	return 0;
}
