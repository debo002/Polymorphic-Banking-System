#pragma once
#include "Savings.h"

class Trust : public Savings {
public:
    Trust(std::string name = "Unnamed", double balance = 0.0, double interest = 0.0, int withdrawals_allowed = 3);
    ~Trust() override = default;

    bool deposit(double amount) override;   // maybe special bonus rules
    bool withdraw(double amount) override;  // track number of withdrawals

    void print(std::ostream& os) const override;

private:
    int withdrawals;          // number of withdrawals performed
    int max_withdrawals;      // allowed number of withdrawals
};
