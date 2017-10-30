// main.cpp
int main()
{
	int x = 5, y = 0;
	// pointer nPtr points to constant data
	// however data may be changed but not 
	// through pointer!
	const int* nPtr = &x;

	// change value of variable x
	x = 10; 

	// this is not allowed-compile error!
	// pointer is pointing to "as" data is "const"
	// meanining, cannot be changed
	// main.cpp:17:10: error: assignment of read-only location ‘* nPtr’
	*nPtr = 12;
	
	// pointer is not constant!
	// point to any address
	nPtr = &y;
	
	return 0;	
}
