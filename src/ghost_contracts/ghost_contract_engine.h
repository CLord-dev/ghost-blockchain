// Copyright (c) 2024, The Ghost Project
#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace ghost
{
  class ghost_contract_engine
  {
  public:
    bool init(const std::string& db_path);
    void shutdown();

    // Deploy a contract
    bool deploy_contract(const std::string& sender, const std::string& bytecode, uint64_t gas_limit, std::string& contract_address);

    // Call a contract
    bool call_contract(const std::string& sender, const std::string& contract_address, const std::string& data, uint64_t gas_limit, std::string& result);

    // Token operations
    bool mint_token(const std::string& contract_address, const std::string& to, uint64_t amount);
    bool transfer_token(const std::string& contract_address, const std::string& from, const std::string& to, uint64_t amount);
    uint64_t get_balance(const std::string& contract_address, const std::string& address);

  private:
    bool m_initialized = false;
    std::string m_db_path;
  };
} // namespace ghost
