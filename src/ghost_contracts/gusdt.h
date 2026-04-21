// Copyright (c) 2024, The Ghost Project
// GUSDT - Ghost USD Stablecoin (GRC-20)
#pragma once
#include "grc20.h"

namespace ghost
{
  class gusdt : public grc20_token
  {
  public:
    std::string owner;
    
    gusdt(const std::string& _owner)
      : grc20_token("Ghost USD", "GUSDT", 12), owner(_owner) {}

    bool mint_stable(const std::string& to, uint64_t amount);
    bool burn(const std::string& from, uint64_t amount);
    bool is_owner(const std::string& address) const;
  };
} // namespace ghost
