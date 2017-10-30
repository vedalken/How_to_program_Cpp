#include <iostream>
#include <cstdlib>
#include <iomanip>

void multiTable(int **table, const int, const int);
void printTable(const int * const *table, const int, const int);

int main(int argc, char *argv[])
{
    int rows, columns;

    if (argc < 2) {
        std::cerr << "Usage:\n"
            << argv[0] << " [rows] [columns]" << std::endl;
        return 1;
    }
    else if (argc < 3) {
        // +1 not to count zero
        rows    = std::atoi(argv[1]) + 1;
        columns = rows;
    }
    else if (argc == 3) {
        rows    = std::atoi(argv[1]) + 1;
        columns = std::atoi(argv[2]) + 1;
    }
    else {
        std::cerr << "To much parameters" << std::endl;
        std::cerr << "Usage: " << argv[0] << " [rows] [columns]" << std::endl;
        return 1;
    }
    
    // Multiplication table
    int **multi_table = new int*[rows];
    
    for (int row = 0; row < rows; ++row) {
        multi_table[ row ] = new int [columns];  
    }
    
    multiTable(multi_table, rows, columns);
    printTable(multi_table, rows, columns);

    for (int row = 0; row < rows; ++row) {
        delete[] multi_table[ row ]; 
    }
    delete[] multi_table;
    
    return 0;
}

void multiTable(int **table, const int a_rows, const int a_columns)
{
    for (int row = 0; row < a_rows; ++row) {
        for (int column = 0; column < a_columns; ++column) {
            table[ row ][ column ] = row * column;
        }
    }
}

void printTable(const int * const *table, const int a_rows, const int a_columns)
{
    for (int row = 1; row < a_rows; ++row) {
        for (int column = 1; column < a_columns; ++column) {
            std::cout << std::setw(5) << table[ row ][ column ];
        }
        std::cout << '\n';
    }
}
