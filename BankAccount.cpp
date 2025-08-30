#include "BankAccount.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
BankAccount::BankAccount(const std::string ownerName, const std::string iban, double balance):ownerName(ownerName),iban(iban),balance(balance){}
std::vector <transaction> transactions;
double balance;
void BankAccount::addTransaction(const transaction& t) {
    Transactions.push_back(t);
    balance+=t.getAmount();
}
double BankAccount::getBalance() const {
    return balance;
}

const std::string BankAccount::getOwnerName() const {
    return ownerName;
}
const std::string BankAccount::getIban() const {
    return iban;
}
const std::vector<transaction> &BankAccount::getTransactions() const {
    return transactions;
}
void BankAccount::savetoFile(const std::string &filename, char divider) const
     {
    std::ofstream file(filename);
    if(!file.is_open()) {
        throw std::runtime_error("Error opening file");
    }
    for (const auto& t : Transactions) {
        file << t.toCsv(divider) << "\n";
    }
}

void BankAccount::loadFromFile(const std::string &filename, char divider)  {
    std::ifstream file(filename);
    if(!file.is_open()) {
        throw std::runtime_error("Error opening file for the reading");
    }
    std::string line;
    while(std::getline(file, line)) {
        if(!line.empty()) {
            transaction t=transaction::fromCsv(line, divider);
            addTransaction(t);
        }
    }
}
void BankAccount::printAccount() const {
    std::cout <<"Bank account --> " <<"Owner:"<< ownerName << " IBAN:" << iban << " current balance: " << balance <<"EUR"<<"\n Transactions:"<< std::endl;
    if(Transactions.empty()) {
        std::cout<<"No transactions."<<std::endl;
    }else {
    for(const auto& t : Transactions) {
            std::cout<<"  \n Date: "<<t.getDate()<<"\n";
            std::cout<<" Time: "<<t.getTime()<<"\n";
            std::cout<<" Amount: "<<t.getAmount()<<"EUR \n";
            std::cout<<" Description:"<<t.getDescription()<<"\n";
        }
    }
}