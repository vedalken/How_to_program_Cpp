#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package
{
    public:
        TwoDayPackage(
            double a_wight,
            const std::string& a_nameSender,
            const std::string& a_nameRecv,
            const std::string& a_addressSender,
            const std::string& a_addressRecv,
            const std::string& a_citySender,
            const std::string& a_cityRecv,
            const std::string& a_stateSender,
            const std::string& a_stateRecv,
            const std::string& a_zipcodeSender,
            const std::string& a_zipcodeRecv,
            double a_fee = 2.0);
    
        double calculateCost() const;
    private:
        double m_fee;

        void setFee(double);
        inline double getFee() const { return m_fee; }
};

#endif
