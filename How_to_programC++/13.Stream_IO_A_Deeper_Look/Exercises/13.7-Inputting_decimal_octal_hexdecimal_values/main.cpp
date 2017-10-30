#include <iostream>
#include <string>

int main()
{
    int value;
    std::string strValue;

    // tie stdout with stdin (default)
    std::cin.tie( &std::cout );

    std::cout << "Enter a integer: ";
    std::getline( std::cin, strValue );

    try {
        // check base type
        if ( strValue[0] == '0' && (strValue[1] == 'x' || strValue[1] == 'X') )
            value = std::stoi( strValue, nullptr, 16 );
        else if ( strValue[0] == '0' )
            value = std::stoi( strValue, nullptr, 8 );
        else
            value = std::stoi( strValue );
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Input number is out of range: " << oor.what() << std::endl;
        return 1;
    }
    catch ( const std::invalid_argument &ia )
    {
        std::cerr << "Invalid input argument: " << ia.what() << std::endl;
        return 1;
    }

    std::cout << std::showbase;
    std::cout << std::dec << value << '\n'
              << std::oct << value << '\n'
              << std::hex << value << std::endl;

    return 0;
}
