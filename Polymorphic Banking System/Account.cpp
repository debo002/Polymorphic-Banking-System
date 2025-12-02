#include "Account.h"

Account::Account(std::string name, double balance)
    : name(std::move(name)), balance(balance) {
}

std::string Account::get_name() const {
    return name;
}

double Account::get_balance() const {
    return balance;
}