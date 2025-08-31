#include <gtest/gtest.h>
#include "../BankAccount.h"
#include "../Transaction.h"
TEST(BankAccountTest, BalanceUpdatesCorrectly) {
    BankAccount MyAccount("Matteo Proto", "IT60X0542811101000000123456", 200.0);
    BankAccount MyAccount_("Giovanni Proto","IT60X0182411101000000125356",400.0);
    transaction t1("25-08-2025", "15:00", -75.0, "gift");
    transaction t2("25-08-2025", "18:00", 17.0, "Refund");
    MyAccount.addTransaction(t1);
    MyAccount.addTransaction(t2);
    MyAccount.savetoFile("Transactions.csv");
    MyAccount_.loadFromFile("Transactions.csv");
    EXPECT_DOUBLE_EQ(MyAccount.getBalance(), 142.0);
    EXPECT_DOUBLE_EQ(MyAccount_.getBalance(), 342.0);
}
