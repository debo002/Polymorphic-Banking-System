#include "AccountUtil.h"
#include <iostream>

void display_accounts(const std::vector<Account*>& accounts) {
    for (auto p : accounts) {
        if (p) std::cout << *p << '\n';   // dereference -> calls IPrintable::operator<< -> print()
    }
}

void deposit_accounts(std::vector<Account*>& accounts, double amount) {
    for (auto p : accounts) {
        if (p) p->deposit(amount);        // virtual call; derived deposit executed
    }
}

void withdraw_accounts(std::vector<Account*>& accounts, double amount) {
    for (auto p : accounts) {
        if (p) p->withdraw(amount);       // virtual call
    }
}
