// sortFunctions.h
// Header contains different sorting functions
#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H
void sortBubble( int [], const int ); // bubble sort

// Bubble sort modification:
// - on each pass, one element is already sorted
//   (the highest element). There is no need to 
//   compare each unsorted element with it!
// - at each pass, check if array is already sorted
void sortBubbleM( int [], const int );

void sortSelect( int [], const int ); // selection sort
void sortInsert( int [], const int ); // insertion sort
#endif
