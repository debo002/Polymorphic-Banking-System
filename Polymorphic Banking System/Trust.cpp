#include "Trust.h"
#include <iomanip>

Trust::Trust(std::string name, double balance, double interest, int withdrawals_allowed)
    : Savings(std::move(name), balance, interest), withdrawals(0), max_withdrawals(withdrawals_allowed) {
}

bool Trust::deposit(double amount) {
    if (amount <= 0.0) return false;
    // For trust: if deposit >= 5000, add fixed bonus (example behavior)
    bool ok = Savings::deposit(amount);
    if (!ok) return false;
    // no additional bookkeeping here (Savings already applied interest)
    return true;
}

bool Trust::withdraw(double amount) {
    if (amount <= 0.0) return false;
    if (withdrawals >= max_withdrawals) return false; // limit reached
    // Optionally limit withdrawal to a percent of balance (not enforced here)
    if (amount <= get_balance()) {
        // we need to reduce balance stored in Account; Savings::withdraw uses balance protected
        // but Savings::withdraw is public and will adjust balance; use it and then increment counter
        bool ok = Savings::withdraw(amount);
        if (ok) {
            ++withdrawals;
            return true;
        }
    }
    return false;
}

void Trust::print(std::ostream& os) const {
    os.setf(std::ios::fixed); os.precision(2);
    os << "Trust Account - Name: " << get_name()
        << " | Balance: " << get_balance()
        << " | Interest: " << get_interest_rate() << "%"
        << " | Withdrawals: " << withdrawals;
}