#pragma once
#include "Account.h"

// Savings account with interest applied on deposits
class Savings : public Account {
public:
    Savings(std::string name = "Unnamed", double balance = 0.0, double interest = 0.0);
    ~Savings() override = default;

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void print(std::ostream& os) const override;

    double get_interest_rate() const { return interest_rate; }

private:
    double interest_rate; // Stored as percentage (e.g., 2.5 = 2.5%)
};