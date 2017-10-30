#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
    public:
        Package(
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
            const std::string& a_zipcodeRecv);

        double calculateCost() const;
    private:
        double      m_weight; // in ounces
        std::string m_nameSender;
        std::string m_nameRecv;
        std::string m_addressSender;
        std::string m_addressRecv;
        std::string m_citySender;
        std::string m_cityRecv;
        std::string m_stateSender;
        std::string m_stateRecv;
        std::string m_zipcodeSender;
        std::string m_zipcodeRecv;

        void setWeight(double);
        void setNameSender(const std::string& );
        void setNameRecv(const std::string& );
        void setAddressSender(const std::string& );
        void setAddressRecv(const std::string& );
        void setCitySender(const std::string& );
        void setCityRecv(const std::string& );
        void setStateSender(const std::string& );
        void setStateRecv(const std::string& );
        void setZipcodeSender(const std::string& );
        void setZipcodeRecv(const std::string& );
};

#endif
