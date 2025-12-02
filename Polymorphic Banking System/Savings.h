#pragma once
#include "Account.h"

class Savings : public Account {
public:
    Savings(std::string name = "Unnamed", double balance = 0.0, double interest = 0.0);
    ~Savings() override = default;

    bool deposit(double amount) override;
    bool withdraw(double amount) override;

    void print(std::ostream& os) const override;

    double get_interest_rate() const { return interest_rate; }

private:
    double interest_rate; // percent (e.g., 2.5 means 2.5%)
};