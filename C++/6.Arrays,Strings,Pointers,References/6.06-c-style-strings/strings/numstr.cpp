// numstr.cpp
// Reading number and string, however there is a trick!
#include <iostream>
int main()
{
	using namespace std;
	cout << "What year was your house built?\n";
	int yearHouseBuilt;
	cin >> yearHouseBuilt;
	// after pressing enter, new line is still input queue
	// meaning next input will get '\n' as first input end
	// will exit (as empty string input!)
	// use cin.get() to discard newline character!
	cin.get();
	
	cout << "What is your street address?\n";
	char streetAddress[ 80 ];
	cin.getline( streetAddress, 80 );

	cout << "Year built: " << yearHouseBuilt << '\n';
	cout << "Street address: " << streetAddress << '\n';
	cout << "Done!" << endl;

	return 0;	
}
