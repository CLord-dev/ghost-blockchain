set(ghost_contracts_sources
  ghost_contract_engine.cpp
  grc20.cpp
  gusdt.cpp
)

set(ghost_contracts_headers
  ghost_contract_engine.h
  grc20.h
  gusdt.h
)

add_library(ghost_contracts
  ${ghost_contracts_sources}
  ${ghost_contracts_headers}
)

target_link_libraries(ghost_contracts
  PRIVATE
    ${CMAKE_SOURCE_DIR}/external/evmone/build/lib/libevmone.a
)

target_include_directories(ghost_contracts
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/external/evmone/include
    ${CMAKE_SOURCE_DIR}/external/evmone/evmc/include
)
