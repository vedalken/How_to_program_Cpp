#include <map>

const int daysPerYear(365);

// Fuel emission [kg CO2e/L] 
// Source:https://www.epa.gov/sites/production/files/2015-07/documents/emission-factors_2014.pdf
const std::map<std::string, double> fuelEmission{
    { "petrol",      2.32 },
    { "gasoline",    2.32 },
    { "disel",       2.70 },
    { "oil",         2.98 }, // residual fuel oil
    { "natural gas", 1.50 }, // liquefied natural gas
    { "lpg",         1.18 }  // liquefied petroleum gas
};

// Electricity emission [kg CO2e/kWh]
// average carbon intensity of electricity use
const double electricityEmission(0.7);

// unknown emission
const double waterEmission(0.0);
