#include <iostream>

std::ostream& bell( std::ostream& out)
{
    return out << '\a';
}

std::ostream& carriageReturn( std::ostream& out )
{
    return out << '\r';
}

std::ostream& tab( std::ostream& out )
{
    return out << '\t';
}

std::ostream& endLine( std::ostream& out)
{
    return out << '\n' << std::flush;
}

int main()
{
    std::cout << "Testing the tab manipulator: " << endLine
        << 'a' << tab << 'b' << tab << 'c' << endLine;

    std::cout << "Testing the carriageReturn and bell manipulators:"
        << endLine << "..........";

    std::cout << bell;
    std::cout << carriageReturn << "------" << endLine;

    return 0;
}
