// Checking.cpp
#include "Checking.h"
#include <iostream>

Checking::Checking(std::string name, double balance)
    : Account(std::move(name), balance) {
}

bool Checking::deposit(double amount) {
    // simple behavior: call base implementation (or custom)
    balance += amount;
    return true;
}

bool Checking::withdraw(double amount) {
    if (amount <= balance) { balance -= amount; return true; }
    return false;
}

void Checking::print(std::ostream& os) const {
    os.setf(std::ios::fixed); os.precision(2);
    os << "Checking: " << name << " balance: " << balance;
}
