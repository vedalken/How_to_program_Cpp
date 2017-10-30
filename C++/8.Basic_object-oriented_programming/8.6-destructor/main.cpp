#include <iostream>
#include "MyString.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage:"
            << "\n\t" << argv[0] << " [name]" << std::endl;
        return -1;
    }
    
    for (int i = 1; i <= argc-1; ++i) 
    {
        MyString myName(argv[i]);
        std::cout << "Your name is " << myName.GetString() << std::endl;
    }

    return 0;
}
