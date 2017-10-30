#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount(double a_balance, double a_fee);
    bool credit(double a_credit);
    bool debit(double a_debit);

    inline double fee() const;
private:
    // charged transaction fee
    double m_fee;

    void fee(double a_fee);
};

#endif
