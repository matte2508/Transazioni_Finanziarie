#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "BankAccount.h"
int main() {
    BankAccount MyAccount("Matteo Proto","IT60X0542811101000000123456",200.0);
  transaction t1("25-08-2025", "15:00",-75.0, "Gift");
    transaction t2("25-08-2025","17:30",17.0,"Refund");
    MyAccount.addTransaction(t1);
    MyAccount.addTransaction(t2);
    MyAccount.printAccount();
    MyAccount.savetoFile("Transactions.csv");
    BankAccount MyAccount_("Giovanni Proto","IT60X0182411101000000125356",400.0);
    MyAccount_.loadFromFile("Transactions.csv");
    std::cout<<"Transactions loaded from file:"<<std::endl;
    MyAccount_.printAccount();
}
