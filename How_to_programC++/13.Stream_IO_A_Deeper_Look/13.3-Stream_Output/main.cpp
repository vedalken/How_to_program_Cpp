#include <iostream>

int main()
{
    const char * const word = "again";

    // stream insertion operator is overloaded for char objects, therefor
    // extracting address of the object is posible through cast operator
    std::cout << "Value of word is: " << word << std::endl
        << "Value of static_cast<const void *>(word) is: "
        << static_cast<const void *>(word) << std::endl;
    
    std::cout.put(65).put(65).put('\n');
    return 0;
}
