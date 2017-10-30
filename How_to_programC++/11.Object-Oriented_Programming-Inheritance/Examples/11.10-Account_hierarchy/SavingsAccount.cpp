#include <stdexcept>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double a_balance, double a_interestRate)
    : Account(a_balance)
{
    setInterestRate(a_interestRate);
}

double SavingsAccount::calculateInterest() const
{
    return Account::getBalance() * getInterestRate();
}

void SavingsAccount::setInterestRate(double a_interestRate)
{
    if (a_interestRate < 1.0 || a_interestRate < 0.0)
        throw std::invalid_argument("Invalid interest rate");
    
    m_interestRate = a_interestRate;
}

double SavingsAccount::getInterestRate() const
{
    return m_interestRate;
}
