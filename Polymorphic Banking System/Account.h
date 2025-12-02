#pragma once
#include <string>
#include "IPrintable.h"

class Account : public IPrintable {
public:
    Account(std::string name = "Unnamed", double balance = 0.0);
    virtual ~Account() = default;                     // virtual destructor

    // pure virtual -> Account becomes abstract
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;

    // accessors
    std::string get_name() const;
    double get_balance() const;

protected:
    std::string name;
    double balance;
};
