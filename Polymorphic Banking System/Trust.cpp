#include "Trust.h"
#include <iomanip>

Trust::Trust(std::string name, double balance, double interest, int withdrawals_allowed)
    : Savings(std::move(name), balance, interest), withdrawals(0), max_withdrawals(withdrawals_allowed) {
}

bool Trust::deposit(double amount) {
    if (amount <= 0.0) return false;
    // Delegates to Savings deposit (includes interest bonus)
    return Savings::deposit(amount);
}

bool Trust::withdraw(double amount) {
    if (amount <= 0.0) return false;

    // Check withdrawal limit
    if (withdrawals >= max_withdrawals) return false;

    if (amount <= get_balance()) {
        bool success = Savings::withdraw(amount);
        if (success) {
            ++withdrawals;
            return true;
        }
    }
    return false;
}

void Trust::print(std::ostream& os) const {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << "Trust Account - Name: " << get_name()
        << " | Balance: " << get_balance()
        << " | Interest: " << get_interest_rate() << "%"
        << " | Withdrawals: " << withdrawals;
}