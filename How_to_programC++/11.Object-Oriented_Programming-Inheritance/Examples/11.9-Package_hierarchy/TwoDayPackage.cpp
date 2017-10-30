#include <stdexcept>
#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(
    double a_weight,
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
    double a_fee)
    : Package(a_weight, a_nameSender, a_nameRecv, a_addressSender, a_addressRecv,
              a_citySender, a_cityRecv, a_stateSender, a_stateRecv,
              a_zipcodeSender, a_zipcodeRecv)
{
    // two day fee
    setFee(a_fee);
}

double TwoDayPackage::calculateCost() const
{
   return getFee() * Package::calculateCost(); 
}

void TwoDayPackage::setFee(double a_fee)
{
    if (a_fee > 0.0)
        m_fee = a_fee;
    else
        throw std::invalid_argument("Fee is negative");
}
