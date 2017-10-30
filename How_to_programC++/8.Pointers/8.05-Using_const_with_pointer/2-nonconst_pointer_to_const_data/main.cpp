// main.cpp
// Attempting to modify data through a nonconstant
// pointer to constant data.
void f( const int* );
int main()
{
	int y = 0;
	f( &y ); // attempt to modify data

	return 0;	
}

// function takes a pointer to constant integer
void f( const int* nPtr )
{
	// attempt to modify constant value
	*nPtr = 100; // compilation error!
}
