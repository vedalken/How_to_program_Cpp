#include <iostream>
#include <cassert>

int	g_array[10] = {0};

int getArrayValue( const int index )
{
	assert( index >= 0 && index <= 9 );

	return g_array[ index ];
}

int main()
{
	getArrayValue(-3);

	return 0;
}
