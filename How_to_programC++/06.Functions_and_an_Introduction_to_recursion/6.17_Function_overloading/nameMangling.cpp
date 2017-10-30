// nameMangling.cpp
// Name mangling.
// run: nm nameMangling | less

// Overload square function
int square( int x ) {
	return x * x;
}

double square( double x ) {
	return x * x;
} 

// Function does nothing. Receives arguments of types int, int, char
// and reference to integer
void nothing1( int a, int b, char c, int &d ) {
	// do nothing
}

int nothing2( char a, int &b, float &c, double &d ) {
	return 0;
}

int main()
{
	return 0; 
}
