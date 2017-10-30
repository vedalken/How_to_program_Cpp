// pop_back.cpp
// Using pop_back member function to remove
// last element in array.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> vecVector;
	vecVector.push_back( 100 );	
	vecVector.push_back( 200 );
	vecVector.push_back( 300 );

	cout << "Size: " << vecVector.size() << endl;
	cout << "Last element: " << vecVector.back() << endl;

	// remove last element
	vecVector.pop_back();
	
	cout << "Remove last element!" << endl;
	cout << "Size: " << vecVector.size() << endl;

	for ( size_t i = 0; i < vecVector.size(); ++i )
		cout << vecVector.at( i ) << endl;
	
	int sum = 0;

	// erase all elements
	while ( !vecVector.empty() ) 
	{
		sum += vecVector.back();
		vecVector.pop_back();
	}

	cout << "Sum = " << sum << endl;

	return 0;	
}
