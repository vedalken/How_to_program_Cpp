#include <stdexcept>
#include "Package.h"

Package::Package(
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
    const std::string& a_zipcodeRecv)
{
    setWeight(a_weight);
    setNameSender(a_nameSender);
    setNameRecv(a_nameRecv);
    setAddressSender(a_addressSender);
    setAddressRecv(a_addressRecv);
    setCitySender(a_citySender);
    setCityRecv(a_cityRecv);
    setStateSender(a_stateSender);
    setStateRecv(a_stateRecv);
    setZipcodeSender(a_zipcodeSender);
    setZipcodeRecv(a_zipcodeRecv);
}

double Package::calculateCost() const
{
    const double costPerOunce = 1.0;
    return m_weight * costPerOunce;
}

void Package::setWeight(double a_weight)
{
    if (a_weight > 0.0)
        m_weight = a_weight;
    else
        throw std::invalid_argument("Weight is negative");
}

void Package::setNameSender(const std::string& a_name)
{
    m_nameSender = a_name; // validate
}

void Package::setNameRecv(const std::string& a_name)
{
    m_nameRecv = a_name; // validate
}

void Package::setAddressSender(const std::string& a_address)
{
    m_addressSender = a_address; // validate
}

void Package::setAddressRecv(const std::string& a_address)
{
    m_addressRecv = a_address; // validate
}

void Package::setCitySender(const std::string& a_city)
{
    m_citySender = a_city; // validate
}

void Package::setCityRecv(const std::string& a_city)
{
    m_cityRecv = a_city; // validate
}

void Package::setStateSender(const std::string& a_state)
{
    m_stateSender = a_state; // validate
}

void Package::setStateRecv(const std::string& a_state)
{
    m_stateRecv = a_state; // validate
}

void Package::setZipcodeSender(const std::string& a_zipcode)
{
    m_zipcodeSender = a_zipcode; // validate
}

void Package::setZipcodeRecv(const std::string& a_zipcode)
{
    m_zipcodeRecv = a_zipcode; // validate
}

