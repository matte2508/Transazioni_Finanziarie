#include <gtest/gtest.h>
#include "../Transaction.h"
TEST(TransactionTest, StoresCorrectData) {
    transaction t1("25-08-2025", "15:00", -75.0, "Gift");
    EXPECT_EQ(t1.getDate(), std::string("25-08-2025"));
    EXPECT_EQ(t1.getTime(), std::string("15:00"));
    EXPECT_DOUBLE_EQ(t1.getAmount(), -75.0);
    EXPECT_EQ(t1.getDescription(), "Gift");
    transaction t2("25-08-2025", "17:00", 17.0, "Refund");
    EXPECT_EQ(t2.getDate(), std::string("25-08-2025"));
    EXPECT_EQ(t2.getTime(), std::string("17:00"));
    EXPECT_DOUBLE_EQ(t2.getAmount(), 17.0);
    EXPECT_EQ(t2.getDescription(), "Refund");
}