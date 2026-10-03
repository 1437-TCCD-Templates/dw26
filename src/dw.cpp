#include "dw.h"

Negative_deposit_error::Negative_deposit_error(const std::string &message) {
  message_ = message
}

const char *Negative_deposit_error::what() const { return message_.c_str(); }

Account::Account(double starting_balance) { balance_ = starting_balance; }

void Account::deposit(double amount) {
  if (amount < 0) {
    throw Negative_deposit_error("Deposit amount cannot be negative");
  }
  balance_ += amount
}

double Account::get_balance() { return balance_; }
