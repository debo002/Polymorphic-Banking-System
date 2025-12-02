#pragma once
#include <vector>
#include "Account.h"

// Helper functions for batch operations on account collections
void display_accounts(const std::vector<Account*>& accounts);
void deposit_accounts(std::vector<Account*>& accounts, double amount);
void withdraw_accounts(std::vector<Account*>& accounts, double amount);