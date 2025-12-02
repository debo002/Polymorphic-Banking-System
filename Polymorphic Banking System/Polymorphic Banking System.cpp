#include <iostream>
#include <vector>
#include "Checking.h"
#include "Savings.h"
#include "Trust.h"
#include "AccountUtil.h"

int main() {
    std::cout << "=== Polymorphic Accounts Demo ===\n\n";

    // Stack objects (direct concrete object use)
    Checking c{ "Frank", 5000.0 };
    Savings s{ "Frank Savings", 5000.0, 2.6 };
    std::cout << c << '\n';
    std::cout << s << '\n';

    // Base pointer to dynamically allocated Trust (polymorphic)
    Account* p = new Trust{ "Leo", 10000.0, 2.6, 3 };
    std::cout << *p << '\n';   // should call Trust::print (dynamic)

    // Create mixed vector of base pointers
    std::vector<Account*> accounts;
    accounts.push_back(new Checking{ "Larry", 1000.0 });
    accounts.push_back(new Savings{ "Moe", 2000.0, 2.5 });
    accounts.push_back(new Trust{ "Curly", 3000.0, 2.0, 3 });

    std::cout << "\n-- initial accounts --\n";
    display_accounts(accounts);

    std::cout << "\n-- deposit 1000 to all --\n";
    deposit_accounts(accounts, 1000.0);
    display_accounts(accounts);

    std::cout << "\n-- withdraw 2000 from all --\n";
    withdraw_accounts(accounts, 2000.0);
    display_accounts(accounts);

    // cleanup
    delete p;
    for (auto ap : accounts) delete ap;
    accounts.clear();

    return 0;
}
