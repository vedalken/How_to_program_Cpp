#include <iostream>

int main()
{
    int integerValue;

    std::cout << "Before a bad input operation:"
        << "\ncin.rdstate(): " << std::cin.rdstate()
        << "\ncin.eof():     " << std::cin.eof()
        << "\ncin.fail():    " << std::cin.fail()
        << "\ncin.bad():     " << std::cin.bad()
        << "\ncin.good():    " << std::cin.good()
        << "\n\nExpects an integer, but enter a character: ";

    std::cin >> integerValue;

    std::cout << "\n\nAfter a bad input operation:"
        << "\ncin.rdstate(): " << std::cin.rdstate()
        << "\ncin.eof():     " << std::cin.eof()
        << "\ncin.fail():    " << std::cin.fail()
        << "\ncin.bad():     " << std::cin.bad()
        << "\ncin.good():    " << std::cin.good();
    
    // clear stream
    std::cin.clear( std::ios::goodbit ); // equivalent to std::cin.clear()

    std::cout << "\n\nAfter cin.clear( ios::goodbit ):"
        << "\ncin.rdstate(): " << std::cin.rdstate()
        << "\ncin.eof():     " << std::cin.eof()
        << "\ncin.fail():    " << std::cin.fail()
        << "\ncin.bad():     " << std::cin.bad()
        << "\ncin.good():    " << std::cin.good();

    std::cout << std::endl;
    return 0;
}
