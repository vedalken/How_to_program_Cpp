#include <iostream>
#include <stdexcept>
#include "Connect4.h"

int main()
{
    Connect4 connect4;
    
    connect4.printBoard();
    connect4.start('+', '*');

    return 0;
}
