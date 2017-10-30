// a.cpp
// Sum odd integers from 1 to 99 using for loop.
#include <iostream>

int main()
{
    int oddSum = 0; // initial value of sum

    // Loop over odd numbers and sum them
    for (int i=1; i<100; i+=2) {
        oddSum += i;
    }

    std::cout << "Sum odd integers from 1 to 99.";
    std::cout << "\nSum: " << oddSum << std::endl;

    return 0;
}
