#include <iostream>
#include "TwoDayPackage.h"

int main()
{
    TwoDayPackage FedEx(13,
        "John",                "Mike",
        "Broadcast street 15", "NewYork street 241",
        "Vancouver",           "ada",
        "dada",                "dsada",
        "dasadas",             "dada");
    
    std::cout << "calculateCost: " << FedEx.calculateCost() << std::endl;

    return 0;
}
