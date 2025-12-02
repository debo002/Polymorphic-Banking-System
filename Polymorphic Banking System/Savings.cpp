#include "Savings.h"
#include <iomanip>

Savings::Savings(std::string name, double balance, double interest)
    : Account(std::move(name), balance), interest_rate(interest) {
}

bool Savings::deposit(double amount) {
    if (amount <= 0.0) return false;

    // Apply interest bonus to deposit amount
    double bonus = amount * (interest_rate / 100.0);
    balance += (amount + bonus);
    return true;
}

bool Savings::withdraw(double amount) {
    if (amount <= 0.0) return false;
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Savings::print(std::ostream& os) const {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << "Savings Account - Name: " << name
        << " | Balance: " << balance
        << " | Interest: " << interest_rate << "%";
}