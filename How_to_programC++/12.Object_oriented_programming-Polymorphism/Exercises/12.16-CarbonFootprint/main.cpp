#include <iostream>
#include <vector>
#include <functional>
#include "CarbonFootprint.h"
#include "Car.h"
#include "Bicycle.h"
#include "House.h"

int main()
{
    std::vector<std::reference_wrapper<CarbonFootprint>> footprints;
    
    Bicycle giant(15);
    Car toyotaPrius(50, "gasoline", 7);
    House appartment(4, 2500, 0, 0, 80000, 1000);

    footprints.push_back(giant);
    footprints.push_back(toyotaPrius);
    footprints.push_back(appartment);
    
    for (auto& footprint : footprints)
        std::cout << footprint << std::endl;

    return 0;
}
