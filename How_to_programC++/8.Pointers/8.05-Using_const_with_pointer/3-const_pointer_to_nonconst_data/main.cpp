// main.cpp
// Attempting to modify a constant pointer
// to nonconstant data.
int main()
{
	int x = 0, y = 0; // initialize variables

	// constant pointer to integer must be initialized
	// and pointer cannot be changed-memory address
	// must remain unchanged, however values of specified type
	// may change
	int* const nPtr = &x;
	
	*nPtr = 7; // set new value
	nPtr = &y; // compilation error: cannot assign new address!

	return 0;	
}
