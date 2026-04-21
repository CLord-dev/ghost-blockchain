// Copyright (c) 2024, The Ghost Project
#include "grc20.h"

namespace ghost
{

bool grc20_token::mint(const std::string& to, uint64_t amount)
{
    balances[to] += amount;
    total_supply += amount;
    return true;
}

bool grc20_token::transfer(const std::string& from, const std::string& to, uint64_t amount)
{
    if(balances[from] < amount) return false;
    balances[from] -= amount;
    balances[to] += amount;
    return true;
}

bool grc20_token::approve(const std::string& owner, const std::string& spender, uint64_t amount)
{
    allowances[owner][spender] = amount;
    return true;
}

bool grc20_token::transfer_from(const std::string& spender, const std::string& from, const std::string& to, uint64_t amount)
{
    if(allowances[from][spender] < amount) return false;
    if(balances[from] < amount) return false;
    allowances[from][spender] -= amount;
    balances[from] -= amount;
    balances[to] += amount;
    return true;
}

uint64_t grc20_token::balance_of(const std::string& address) const
{
    auto it = balances.find(address);
    if(it == balances.end()) return 0;
    return it->second;
}

uint64_t grc20_token::allowance(const std::string& owner, const std::string& spender) const
{
    auto it = allowances.find(owner);
    if(it == allowances.end()) return 0;
    auto it2 = it->second.find(spender);
    if(it2 == it->second.end()) return 0;
    return it2->second;
}

} // namespace ghost
