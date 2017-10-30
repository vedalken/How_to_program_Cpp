//functions implementation
#include <iostream>
using namespace std;

int ReadNumber()
{
	int num;
	cout << "Please enter a integer number: ";
	cin >> num;
	return num;
}

// display addition result of two numbers
void WriteAnswer(int n1, int n2, int result)
{
	cout << "Result of addition "	<< n1 << \
		" and " << n2 << " is " << result << endl; 
}
