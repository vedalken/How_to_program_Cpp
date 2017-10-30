#include <iostream>
using namespace std;

int main()
{
	
	int number;
	cout << "Enter starting number > ";
	cin >> number;

	while (number>0)
	{
		cout << number << ", ";
		number--;
	}

	cout << "The end.\n";

	return 0;
}
