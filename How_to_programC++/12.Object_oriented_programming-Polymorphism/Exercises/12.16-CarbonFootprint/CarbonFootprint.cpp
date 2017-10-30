#include "CarbonFootprint.h"

std::ostream&
operator<<(std::ostream &out, const CarbonFootprint &footprint)
{
    return footprint.carbonFootprintReport(out);
}

std::ostream&
CarbonFootprint::carbonFootprintReport(std::ostream &out) const
{
    out << "================ Carbon Footprint Report ===============";
    return out;
}
