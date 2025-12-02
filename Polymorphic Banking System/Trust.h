#pragma once
#include "Savings.h"

// Trust account with limited withdrawals per period
// Inherits interest rate from Savings
class Trust : public Savings {
public:
    Trust(std::string name = "Unnamed", double balance = 0.0, double interest = 0.0, int withdrawals_allowed = 3);
    ~Trust() override = default;

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void print(std::ostream& os) const override;

private:
    int withdrawals;        // Current number of withdrawals made
    int max_withdrawals;    // Maximum allowed withdrawals
};