#ifndef CARBON_FOOTPRINT_H
#define CARBON_FOOTPRINT_H
#include <iostream>

const double kilo(1000);

class CarbonFootprint
{
    friend std::ostream& operator<<(std::ostream &, const CarbonFootprint &);
    public:
        CarbonFootprint() {}
        virtual ~CarbonFootprint() {}
        virtual double getCO2Emissions() const = 0;
        virtual double getCarbonFootprint() const = 0;
        virtual std::ostream& carbonFootprintReport(std::ostream &) const;
};

#endif
