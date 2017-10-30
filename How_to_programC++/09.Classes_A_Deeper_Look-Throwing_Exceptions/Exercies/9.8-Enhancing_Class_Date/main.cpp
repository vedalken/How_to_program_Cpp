#include <iostream>
#include "Date.h"

int main()
{
    Date month{1,1,2015};

    for (int i = 1; i <= 31; ++i) {
        month.print();
        std::cout << '\t';
        if (i % 4 == 0) {
            std::cout << '\n';
        }
        month.nextDay();
    }
    
    std::cout << "\n\nNew year...";

    Date newYear{31,12,2015};
    newYear.nextDay();
    newYear.print();

    std::cout << '\n';

	return 0;
}
