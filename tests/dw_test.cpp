#include "dw.h"
#include <gtest/gtest.h>

TEST(Account, DepositIncreasesBalance) {
  Account account(100.0);
  account.deposit(50.0);
  EXPECT_DOUBLE_EQ(account.get_balance(), 150.0);
}

TEST(Account, ThrowsOnNegativeDeposit) {
  Account account(100.0);
  EXPECT_THROW(account.deposit(-10.0), Negative_deposit_error);
}
