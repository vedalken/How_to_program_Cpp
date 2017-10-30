// Calculate CO2 emission per year cycler produce in traveled distance

#ifndef BICYCLE_H
#define BICYCLE_H

#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint
{
    public:
        Bicycle(double a_km);
        virtual ~Bicycle();
        virtual double getCarbonFootprint() const override;
        virtual double getCO2Emissions() const override;
        virtual std::ostream& carbonFootprintReport(std::ostream &) const override;
    private:
        double m_km; // traveled distance in kilometers per day
};

#endif
