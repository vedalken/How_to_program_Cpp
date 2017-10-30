#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account(double a_balance);

    void   credit(double a_credit);
    void   debit(double a_debit);
    double getBalance() const;

protected:
    void setBalance(double);

private:
    double m_balance;
};

#endif
