// Copyright (c) 2024, The Ghost Project
#include "gusdt.h"

namespace ghost
{

bool gusdt::mint_stable(const std::string& to, uint64_t amount)
{
    if(!is_owner(to) && !is_owner(owner)) return false;
    return mint(to, amount);
}

bool gusdt::burn(const std::string& from, uint64_t amount)
{
    if(balances[from] < amount) return false;
    balances[from] -= amount;
    total_supply -= amount;
    return true;
}

bool gusdt::is_owner(const std::string& address) const
{
    return address == owner;
}

} // namespace ghost
