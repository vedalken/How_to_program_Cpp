#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main()
{
    const double balance = 1000;
    const double fee = 1;
    const double credit = 135;
    const double debit = 5;

    CheckingAccount cAccount(balance, fee);
    
    std::cout << "balance: " << cAccount.getBalance() << std::endl;
    
    cAccount.credit(135); 
    std::cout << "balance: " << cAccount.getBalance() << std::endl;
    cAccount.debit(5);
    
    std::cout << "fee: " << fee << "\ncredit: " << credit << "\ndebit: " << debit;
    std::cout << "\nbalance: " << cAccount.getBalance() << std::endl;

    try {
        cAccount.debit(99999);
    }
    catch (const std::invalid_argument& ia) {
        std::cout << "Invalid argument: " << ia.what() << std::endl;
    }

    return 0;
}
