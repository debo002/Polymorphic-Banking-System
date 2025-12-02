#pragma once
#include <string>
#include "IPrintable.h"

// Abstract base class for all account types
// Provides common interface and shared data members
class Account : public IPrintable {
public:
    Account(std::string name = "Unnamed", double balance = 0.0);
    virtual ~Account() = default;

    // Pure virtual functions - must be implemented by derived classes
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;

    // Accessor methods for protected members
    std::string get_name() const;
    double get_balance() const;

protected:
    // Protected members accessible by derived classes
    std::string name;
    double balance;
};