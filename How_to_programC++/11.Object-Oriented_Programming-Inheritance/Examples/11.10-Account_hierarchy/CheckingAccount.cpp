#include <stdexcept>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double a_balance, double a_fee)
    : Account(a_balance)
{
    fee(a_fee);
}

// credit transaction includes transaction fee per successful transaction
bool CheckingAccount::credit(double a_credit)
{
    if (a_credit <= 0.0)
        return false;

    // fee per successful transaction
    Account::credit(a_credit - fee());

    return true;
}

// debit transaction includes transaction fee per successful transaction
bool CheckingAccount::debit(double a_debit)
{
    if (a_debit <= 0)
        return false;

    Account::debit(a_debit + fee());

    return true;
}

double CheckingAccount::fee() const
{
    return m_fee;
}

void CheckingAccount::fee(double a_fee)
{
    if (a_fee < 0.0)
        throw std::invalid_argument("Invalid transaction fee");

    m_fee = a_fee;
}
