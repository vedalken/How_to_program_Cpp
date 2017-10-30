#include <iostream>
#include <cstdlib>
#include <iomanip>

void multiTable(int ***table, const int a_length, 
                const int a_width, const int a_height);
void printTable(const int * const * const *table, 
                const int, const int, const int);

int main(int argc, char *argv[])
{
    int length, width, height;

    if (argc < 2) {
        std::cerr << "Usage:\n"
            << argv[0] << " [length] [width] [heigth]" << std::endl;
        return 1;
    }
    else if (argc < 3) {
        // +1 not to count zero
        length = std::atoi(argv[1]) + 1;
        width  = length + 1;
        height = length + 1;
    }
    else if (argc == 4) {
        length = std::atoi(argv[1]) + 1;
        width  = std::atoi(argv[2]) + 1;
        height = std::atoi(argv[3]) + 1;
    }
    else {
        std::cerr << "To much parameters" << std::endl;
        std::cerr << "Usage: " << argv[0] << " [length] [width] [height]" << std::endl;
        return 1;
    }
    
    // Multiplication table
    int ***multi_table = new int**[length];
    
    for (int l = 0; l < length; ++l) {
        multi_table[ l ] = new int*[width];
    }
    for (int l = 0; l < length; ++l) {
        for (int w = 0; w < width; ++w) {
            multi_table[ l ][ w ] = new int [height];
        }
    }

    multiTable(multi_table, length, width, height);
    printTable(multi_table, length, width, height);

    // free memory: height 
    for (int l = 0; l < length; ++l) {
        for (int w = 0; w < width; ++w) {
            delete[] multi_table[ l ][ w ];
        }
    }
    // free memory: width
    for (int l = 0; l < length; ++l) {
        delete[] multi_table[ l ];
    }
    // free memory: length
    delete[] multi_table;

    return 0;
}

void multiTable(int ***table, const int a_length, const int a_width, const int a_height)
{
    for (int l = 1; l < a_length; ++l) {
        for (int w = 1; w < a_width; ++w) {
            for (int h = 1; h < a_height; ++h) {
                table[ l ][ w ][ h ] = l * w * h;
            }
        }
    }
}

void printTable(const int * const * const *table, const int a_length, 
                const int a_width, const int a_height)
{
    for (int l = 1; l < a_length; ++l) {
        std::cout << "l: " << l << std::endl;
        for (int w = 1; w < a_width; ++w) {
            for (int h = 1; h < a_height; ++h) {
                std::cout << std::setw(5) << table[ l ][ w ][ h ];
            }// end height
            std::cout << '\n';
        }// end width
        std::cout << '\n';
    }// end length
}
