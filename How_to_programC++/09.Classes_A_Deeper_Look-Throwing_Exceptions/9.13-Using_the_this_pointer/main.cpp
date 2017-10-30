#include <iostream>
#include "Time.h"

int main()
{
    Time t;

    // cascaded function call
    t.setHour(18).setMinute(12).setSecond(33);

    std::cout << "Standard time: ";
    t.standard();
    
    std::cout << "Universal time: ";
    t.universal();

    std::cout << "Changed time...\n";
    
    t.setTime(20,20,20).standard();

    return 0;
}
