#ifndef HOUSE_H
#define HOUSE_H

#include "CarbonFootprint.h"

class House : public CarbonFootprint
{
    public:
        House(size_t a_people, double a_electricityPerYear, double a_gasPerYear,
              double a_fuelOilPerYear, double m_lpgPerYear, double a_waterPerDay);
        virtual ~House();

        virtual double getCarbonFootprint() const override;
        virtual double getCO2Emissions() const override;
        virtual std::ostream& carbonFootprintReport(std::ostream &) const override;
    
        double getCO2EmissionsPerPerson() const;

        // emissions per year
        double getElectricityCO2Emissions() const;
        double getGasCO2Emissions() const;
        double getFuelOilCO2Emissions() const;
        double getLPGCO2Emissions() const;
        double getWaterCO2Emissions() const;
        double getWasteCO2Emissions() const;

    private:
        size_t m_people;
        double m_electricityPerYear; // kWh/year
        double m_gasPerYear;         // kg/year
        double m_fuelOilPerYear;     // L/year
        double m_lpgPerYear;         // kg/year (liquid petroleum gas (LPG))
        double m_waterPerDay;        // L/day
};

#endif
