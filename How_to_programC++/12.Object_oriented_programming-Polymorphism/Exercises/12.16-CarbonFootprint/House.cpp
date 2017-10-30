#include "House.h"
#include "tables.h"

House::House(size_t a_people,
             double a_electricityPerYear,
             double a_gasPerYear,
             double a_fuelOilPerYear,
             double a_lpgPerYear,
             double a_waterPerDay)
    : CarbonFootprint(),
      m_people(a_people <= 0 ? 1 : a_people),
      m_electricityPerYear(a_electricityPerYear),
      m_gasPerYear(a_gasPerYear),
      m_fuelOilPerYear(a_fuelOilPerYear),
      m_lpgPerYear(a_lpgPerYear),
      m_waterPerDay(a_waterPerDay)
{
}

House::~House()
{
}

double
House::getElectricityCO2Emissions() const
{
    return m_electricityPerYear * electricityEmission;
}

double
House::getGasCO2Emissions() const
{
    return m_gasPerYear * fuelEmission.find("natural gas")->second;
}

double
House::getFuelOilCO2Emissions() const
{
    // density ~ 1kg/m^3 ~ 1L/m^3
    return m_fuelOilPerYear * fuelEmission.find("oil")->second;
}

double
House::getLPGCO2Emissions() const
{
    return m_lpgPerYear * fuelEmission.find("lpg")->second;
}

double
House::getWaterCO2Emissions() const
{
    return m_waterPerDay * daysPerYear * waterEmission;
}

double
House::getWasteCO2Emissions() const
{
    // approximate waste disposal emission per person [kg CO2e/year]
    // Source: http://ec.europa.eu/eurostat/statistics-explained/index.php/Archive:Greenhouse_gas_emissions_from_waste_disposal 
    const double emission(350);
    return m_people *  emission;
}

double
House::getCO2Emissions() const
{
    double emission(0);

    emission = getElectricityCO2Emissions() +
               getGasCO2Emissions() +
               getFuelOilCO2Emissions() +
               getLPGCO2Emissions() +
               getWaterCO2Emissions() +
               getWasteCO2Emissions();

    return emission;
}

double
House::getCO2EmissionsPerPerson() const
{
    return getCO2Emissions() / m_people;
}

double
House::getCarbonFootprint() const
{
    return getCO2Emissions();
}

std::ostream&
House::carbonFootprintReport(std::ostream &out) const
{
    CarbonFootprint::carbonFootprintReport(out);

    out << "\nType: House"
        << "\nParameters:"
        << "\n  number of people []: " << m_people
        << "\n  use electricity [kWh/year]: " << m_electricityPerYear
        << "\n  use gas [kg/year]: " << m_gasPerYear
        << "\n  use fuel oil [L/year]: " << m_fuelOilPerYear
        << "\n  use LPG [kg/year]: " << m_lpgPerYear
        << "\n  use water [L/day]: " << m_waterPerDay
        << "\nCO2 emissions per person [person/year]: " << getCO2EmissionsPerPerson()
        << "\nTotal CO2 emissions [kg CO2e/year]: " << getCarbonFootprint() 
        << std::endl;
    
    return out;
}

