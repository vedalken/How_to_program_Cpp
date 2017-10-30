#include <stdexcept>
#include <cmath>
#include "Account.h"

Account::Account(double a_balance)
{
    setBalance(a_balance);
}

void Account::setBalance(double a_balance)
{
    if (a_balance >= 0.0)
        m_balance = a_balance;
    else
        throw std::invalid_argument("Invalid balance");
}

void Account::credit(double a_credit)
{
    if (a_credit >= 0.0)
        m_balance += a_credit;
    else
        throw std::invalid_argument("Invalid credit balance");
}

void Account::debit(double a_debit)
{
    if (a_debit >= 0.0 && a_debit <= m_balance)
       m_balance -= a_debit;
    else
        throw std::invalid_argument("Debit amount exceeded account balance");
}

double Account::getBalance() const
{
    return m_balance;
}
