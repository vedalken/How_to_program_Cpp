#include <iostream>
#include "cstack.h"
#include "stack.h"

int main()
{
    CStack<int> intStack;

    std::cout << "processing and integer Stack" << std::endl;

    for (int i = 0; i < 3; ++i) {
	intStack.push(i);
	intStack.printStack();
    }

    std::cout << "Removing integer stack..." << std::endl;

    int popInteger;
    while ( !intStack.isEmpty() ) {
        intStack.pop(popInteger);
        std::cout << popInteger << " popped from stack" << std::endl;
        intStack.printStack();
    }

    Stack<double> doubleStack;
    std::cout << "processing and double Stack" << std::endl;

    for (int i = 0; i < 3; ++i) {
        doubleStack.push(i * 1.1);
        doubleStack.printStack();
    }

    double popDouble;
    while ( !doubleStack.isEmpty() ) {
        doubleStack.pop(popDouble);
        std::cout << popDouble << " popped from stack" << std::endl;
        doubleStack.printStack();
    }

    return 0;    
}
