//
// Header file: macrosdef.h
//


#ifndef MACROSDEF_H
#define MACROSDEF_H

#include <iostream>
using namespace std;


#ifndef PRINTARRAY
#define PRINTARRAY( array, size ) \
for(int i=0; i < size; ++i) \
{ cout << i << ":\t" << array[i] << endl; }
#endif
// inline function
void inline printArray( double array[], int size )
{
	for ( int i = 0; i < size; ++i )
		cout << i << ":\t" << array[ i ] << endl;
}

#ifndef SUMARRAY
#define SUMARRAY( array, size ) {\
double sum=0.0;\
for(int i=0; i < size; ++i) {sum+=array[i];}\
cout << "Sum: " << sum << endl;}
#endif
// inline function
void sumArray( double array[], int size)
{
	double sum = 0.;
	for ( int i = 0; i < size; ++i )
		sum += array[ i ];
	cout << "Sum: " << sum << endl;
}


#endif
