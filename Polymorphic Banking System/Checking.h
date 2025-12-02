#pragma once
#include "Account.h"

class Checking : public Account {
public:
    Checking(std::string name = "Unnamed", double balance = 0.0);
    ~Checking() override = default;

    bool deposit(double amount) override;
    bool withdraw(double amount) override;

    void print(std::ostream& os) const override;
};
