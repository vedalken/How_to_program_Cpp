// Function add two integer numbers
// and the result is printed by function WriteAnswer();
// run as: g++ -o 2_add2num 2_add2num.cpp io.cpp
#include <iostream>
using namespace std;

// function prototype
// forward declaration
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

