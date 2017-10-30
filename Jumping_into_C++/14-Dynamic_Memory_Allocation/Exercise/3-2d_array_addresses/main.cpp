#include <iostream>

int main()
{
    constexpr int cols = {3};
    constexpr int rows = {2};
    int array[ rows ][ cols ] = {{1,2,3},{4,5,6}};
    
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << "[" << row << "][" << col << "] = " 
                << (*array + col + row * cols) << "\t";
        }
        std::cout << '\n';
    }

    return 0;
}
