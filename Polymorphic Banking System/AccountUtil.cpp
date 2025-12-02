#include "AccountUtil.h"
#include <iostream>

void display_accounts(const std::vector<Account*>& accounts) {
    // Polymorphic printing via IPrintable interface
    for (const auto account : accounts) {
        if (account) std::cout << *account << '\n';
    }
}

void deposit_accounts(std::vector<Account*>& accounts, double amount) {
    // Dynamic dispatch calls appropriate derived class deposit()
    for (auto account : accounts) {
        if (account) account->deposit(amount);
    }
}

void withdraw_accounts(std::vector<Account*>& accounts, double amount) {
    // Dynamic dispatch calls appropriate derived class withdraw()
    for (auto account : accounts) {
        if (account) account->withdraw(amount);
    }
}