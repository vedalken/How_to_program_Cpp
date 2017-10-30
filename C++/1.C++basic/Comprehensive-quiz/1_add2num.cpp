// Function add two integer numbers
// and the result is printed by function WriteAnswer();
#include <iostream>
using namespace std;

// function prototype
int	ReadNumber();
void	WriteAnswer(int n1, int n2, int result);

int main ()
{
	// User enter two numbers
	int n1 = ReadNumber();
	int n2 = ReadNumber();

	// result is printed
	WriteAnswer( n1, n2, n1+n2 );
	
	return 0;
}

// ask user for integer number
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
