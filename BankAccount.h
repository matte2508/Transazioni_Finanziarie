
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <vector>

#include "Transaction.h"

class BankAccount {
    public:
    BankAccount(const std::string owner,const std::string iban, double balance);

    void addTransaction(const transaction& t);

    const std::string getOwner() const;
    const std::string getIban() const;
    double getBalance() const;
    const std::vector<transaction>& getTransactions() const;
    void savetoFile(const std::string &filename, char divider=';') const;
    void loadFromFile(const std::string &filename, char divider=';') ;
    void printAccount() const;
private:
    std::string owner;
    std::string iban;
    std::vector <transaction> Transactions;
    double balance;
};
#endif //BANKACCOUNT_H
