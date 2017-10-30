#include <iomanip>
#include "Bicycle.h"

Bicycle::Bicycle(double a_km)
    : CarbonFootprint(),
      m_km(a_km)
{
}

Bicycle::~Bicycle()
{
}

/** calculate carbon emission per year in units of kilograms
 *  Approximations taken into account:
 *   * all days per year cycler cycle
 *   * average cycled distance per day
 *   * cycler type independent i.e. mass, height, age, ...
 */
double
Bicycle::getCarbonFootprint() const
{
    const int daysPerYear(365);
    const double totalDistance = m_km * daysPerYear;
    double kilo(1000);

    double footprint = getCO2Emissions() * totalDistance;

    // convert grams into kilograms
    footprint /= kilo;

    return footprint;
}

// CO2 emissions gramms per kilometer
double
Bicycle::getCO2Emissions() const
{
    // Source: https://www.eta.co.uk/2011/12/13/co2-emissions-from-cycling-revealed/ 
    static const double emissions(21);

    return emissions;
}

std::ostream&
Bicycle::carbonFootprintReport(std::ostream &out) const
{
    CarbonFootprint::carbonFootprintReport(out);

    out << "\nType: Bicycle"
        << "\nParameters:"
        << "\n  distance traveled [km/day]: " << m_km
        << "\nTotal CO2 emissions [kg CO2e/year]: " << getCarbonFootprint() 
        << std::endl;
    
    return out;
}
