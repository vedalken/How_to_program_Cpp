#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
public:
    SavingsAccount(double a_balance, double a_interestRate);
    double calculateInterest() const;

private:
    double m_interestRate;

    void setInterestRate(double);
    inline double getInterestRate() const;
};

#endif
