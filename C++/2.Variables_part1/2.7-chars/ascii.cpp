#include <iostream>

int main()
{
	using namespace std;

	char chValue1 = 'a';
	char chValue2 = 97;		// assign char with ASCII code 97

	cout << chValue1 << "\n" << chValue2 << endl;

    char charValue;
    cout << "Enter a character: ";
    cin >> charValue;

    cout << charValue << " has ASCII code " << (int)charValue << endl;

	return 0;
}
