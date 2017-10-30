// sort.h
#ifndef SORT_H
#define SORT_H
void bucketSort( int [], const int );
void init2Darray( int [][10], const int );
int get2Dcol( int [][10], const int, const int );
void collectBuckets( int [][10], int [], const int );

// gets i-th digit of integer number
int getDigit( int, const int );

// split number into digits
void getDigits( int [], const int, const int );

// gets maximal number of digits
int maxDigits( int );

// print array
void printArray( int [], const int );

#endif
