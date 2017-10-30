#ifndef CAR_H
#define CAR_H

#include <string>
#include "CarbonFootprint.h"

class Car : public CarbonFootprint
{
    public:
        Car(double a_km, const std::string &a_fuel, double a_avg);
        virtual ~Car();
    
        virtual double getCarbonFootprint() const override;
        virtual double getCO2Emissions() const override;
        virtual std::ostream& carbonFootprintReport(std::ostream &) const override;

    private:
        double m_km;                  // average distance [km/day]
        std::string m_fuel;           // fuel type: disel, petrol (gasoline)
        double m_avgFuelConsumption;  // average fuel consumption [L/100km]

        // helper function
        bool setFuel(const std::string &a_fuel);

};

#endif
