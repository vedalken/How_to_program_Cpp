// voidPointer.cpp
#include <iostream>
enum Type {
	INT, // 0
	DOUBLE, // 1
	STRING // 2
};
void print( void* , Type );
int main()
{
	int nValue = 5;
	double fValue = 3.14159;
	char name[] = "Milos";
	print( &nValue, INT );
	print( &fValue, DOUBLE );
	print( name, STRING );
	return 0;
}

// void pointer points to unknown type, dereferencing
// is not allowed, beacause compile does not know type
// pointer points to.
void print( void* pValue, Type eType )
{
	using namespace std;
	switch ( eType )
	{
		case INT:
			cout << *static_cast<int* >( pValue ) << endl;
			break;
		case DOUBLE:
			cout << *static_cast<double* >( pValue ) << endl;
			break;
		case STRING:
			cout << static_cast<char* >( pValue ) << endl;
			break;
	}
}
