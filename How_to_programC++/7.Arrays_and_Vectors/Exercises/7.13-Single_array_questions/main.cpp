// main.cpp
// Do not run program!
int main()
{
	//(a) initialize 10 elements of integer array to zero
	int counts[ 10 ] = {};
	
	//(b) add 1 to each of the 15 elements of integer array bonus
	for ( int i = 0; i < 15; ++i )
		++bonus[ i ];

	//(c) read 12 values for double array monthlyTemepratures from
	//    keyboard
	for ( int i = 0; i < 12; ++i )
		cin >> monthlyTemperatures[ i ];

	//(d) print 5 values of integer array bestScore in column
	//format
	for ( int i = 0; i < 5; ++i )
		cout << bestScore[ i ] << endl;

	return 0;	
}
