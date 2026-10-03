#ifndef DW_H
#define DW_H

#include <exception>
#include <string>

class Negative_deposit_error : public std::exception {
public:
  Negative_deposit_error(const std::string &message);
  const char *what() const noexcept override;

private:
  std::string message_;
};

class Account {
public:
  Account(double starting_balance);
  void deposit(double amount);
  double get_balance() const;

private:
  double balance_;
};

#endif
