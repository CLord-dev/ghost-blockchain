// Copyright (c) 2024, The Ghost Project
// GRC-20 Token Standard
#pragma once
#include <string>
#include <cstdint>
#include <unordered_map>

namespace ghost
{
  class grc20_token
  {
  public:
    std::string name;
    std::string symbol;
    uint8_t decimals;
    uint64_t total_supply;

    std::unordered_map<std::string, uint64_t> balances;
    std::unordered_map<std::string, std::unordered_map<std::string, uint64_t>> allowances;

    grc20_token(const std::string& _name, const std::string& _symbol, uint8_t _decimals)
      : name(_name), symbol(_symbol), decimals(_decimals), total_supply(0) {}

    bool mint(const std::string& to, uint64_t amount);
    bool transfer(const std::string& from, const std::string& to, uint64_t amount);
    bool approve(const std::string& owner, const std::string& spender, uint64_t amount);
    bool transfer_from(const std::string& spender, const std::string& from, const std::string& to, uint64_t amount);
    uint64_t balance_of(const std::string& address) const;
    uint64_t allowance(const std::string& owner, const std::string& spender) const;
  };
} // namespace ghost
