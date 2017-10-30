#include <iostream>
#include "Date.h"

int main()
{
    Date myDate(3,2,2007);

    std::cout << "The date is " << myDate.GetDate() << std::endl;
    return 0;
}
