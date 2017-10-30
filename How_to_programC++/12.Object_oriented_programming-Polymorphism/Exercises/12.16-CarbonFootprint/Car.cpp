#include <map>
#include "tables.h"
#include "Car.h"

Car::Car(double a_km, const std::string &a_fuel, double a_avg)
    : CarbonFootprint(),
      m_km(a_km),
      m_fuel(), 
      m_avgFuelConsumption(a_avg)
{
    if (! setFuel(a_fuel))
        return;
}

Car::~Car()
{
}

// validate and set fuel type
bool
Car::setFuel(const std::string &a_fuel)
{
    if (fuelEmission.find(a_fuel) == fuelEmission.end())
    {
        std::cerr << "Car with fuel " << a_fuel << " is not available\n";
        return false;
    }

    m_fuel = a_fuel;
    return true;
}

// CO2 emissions gramms per kilometer [g CO2e/km]
double 
Car::getCO2Emissions() const
{
    const int hundredKm(100);
    double result;

    result = m_avgFuelConsumption * fuelEmission.find(m_fuel)->second / hundredKm;
    result *= kilo;

    return result;
}

double
Car::getCarbonFootprint() const
{
    const double totalDistance = m_km * daysPerYear;

    double footprint;
    footprint = getCO2Emissions() * totalDistance;

    // convert grams to kilograms
    footprint /= kilo;

    return footprint;
}

std::ostream&
Car::carbonFootprintReport(std::ostream &out) const
{
    CarbonFootprint::carbonFootprintReport(out);

    out << "\nType: Car"
        << "\nParameters:"
        << "\n  distance traveled [km/day]: " << m_km
        << "\n  fuel type: " << m_fuel
        << "\n  average fuel consumption [L/100km]: " << m_avgFuelConsumption
        << "\nCO2 emissions [g CO2/day]: " << getCO2Emissions()
        << "\nTotal CO2 emissions [kg CO2e/year]: " << getCarbonFootprint() 
        << std::endl;
    
    return out;
}
