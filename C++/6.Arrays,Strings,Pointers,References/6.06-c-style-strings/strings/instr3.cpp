// instr3.cpp - read string with cin.get() function
// with function concatenation delimiter character
// is descarded, second reading input does not 
// read this delimiter
#include <iostream>
int main()
{
	using namespace std;
	const int size = 15;

	cout << "Enter your name:\n";
	char name[ size ];
	cin.get( name, size ).get(); // save name, discard delimiter i.e. '\n'
	cout << "What is your favorit dessert?\n";
	char dessert[ size ];
	cin.get( dessert, size ).get(); // save name, discard new line
	
	cout << "I have some delicious " << dessert << " for you "
		<< name << ".\n";
	return 0;	
}
