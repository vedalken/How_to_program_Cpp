// calcInitializeArray.cpp
// Declare array with constant value and initialize
// with even numbers from 2 to 20.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

int main()
{
    const int arraySize = 10; // initialize array size
    int array[arraySize];     // create array with specified size

    // initialize array elements
    for (int i = 0; i < arraySize; ++i)
        array[i] = 2 * (i + 1);

    cout << setw(7) << "Element" << setw(10) << "Value" << endl;

    // display array's element and value
    for (int i = 0; i < arraySize; ++i)
        cout << setw(7) << i << setw(10) << array[i] << endl;

    return 0;
}
