#include <iostream>

int main()
{
	using namespace std;
	
	cout << "Enter a number: ";
	int nNumber;
	cin >> nNumber;
	
	if (nNumber > 10 && nNumber < 20)
		cout << "Number is between 10 and 20" << endl;
	else
		cout << "Number is not between 10 and 20" << endl;
		
	return 0;
}
