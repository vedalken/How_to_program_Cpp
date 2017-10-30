#include <iostream>
#include <stdexcept>
#include "Time.h"

int main()
{
    Time t{10, 0, 0};

    size_t ticks      = 60; // number of ticks per minute or hour
    size_t min_ticks  = ticks;
    size_t hour_ticks = min_ticks * ticks;

    std::cout << "Ticks in one minute..." << std::endl;
    for (size_t i = 0; i < min_ticks; ++i) {
        t.tick();
        t.printStandard();     
    }
    
    t.setTime(10,0,0);
    std::cout << "Ticks in one hour..." << std::endl;
    for (size_t ticks = 0; ticks < hour_ticks; ++ticks) {
        t.tick();
        t.printStandard();
    }

    Time midnight{11, 59, 59};
    
    std::cout << "Midnight..." << std::endl;
    midnight.tick();
    midnight.printStandard();

    return 0;
}
