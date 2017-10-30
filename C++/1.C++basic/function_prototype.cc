#include <iostream>
using namespace std;

void odd  (int number);
void even (int number);

int main ()
{
	int n;
	do{
		cout << "Enter a number: ";
		cin >> n;
		odd(n);
	} while(n!=0);
	return 0;
}

void odd( int number )
{
	if ( (number % 2) != 0 ) cout << "Number is odd.\n";
	else even(number);
}

void even( int number )
{
	if ( (number % 2) == 0) cout << "Number is even.\n";
	else odd(number);
}
