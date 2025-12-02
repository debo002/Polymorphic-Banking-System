#include <iostream>
#include <vector>
#include "Checking.h"
#include "Savings.h"
#include "Trust.h"
#include "AccountUtil.h"

int main() {
    std::cout << "=== Polymorphic Accounts Demo ===\n\n";

    // Stack-allocated objects for direct usage
    Checking checking{ "Frank", 5000.0 };
    Savings savings{ "Frank Savings", 5000.0, 2.6 };
    std::cout << checking << '\n';
    std::cout << savings << '\n';

    // Base pointer to derived object - enables polymorphism
    Account* trust_ptr = new Trust{ "Leo", 10000.0, 2.6, 3 };
    std::cout << *trust_ptr << '\n';  // Calls Trust::print() dynamically

    // Heterogeneous collection - different account types via base pointers
    std::vector<Account*> accounts;
    accounts.push_back(new Checking{ "Larry", 1000.0 });
    accounts.push_back(new Savings{ "Moe", 2000.0, 2.5 });
    accounts.push_back(new Trust{ "Curly", 3000.0, 2.0, 3 });

    std::cout << "\n-- Initial Accounts --\n";
    display_accounts(accounts);

    // Polymorphic operations - each account type behaves according to its implementation
    std::cout << "\n-- Deposit 1000 to All --\n";
    deposit_accounts(accounts, 1000.0);
    display_accounts(accounts);

    std::cout << "\n-- Withdraw 2000 from All --\n";
    withdraw_accounts(accounts, 2000.0);
    display_accounts(accounts);

    // Manual memory cleanup
    delete trust_ptr;
    for (auto account : accounts) delete account;
    accounts.clear();

    return 0;
}