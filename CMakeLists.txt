cmake_minimum_required(VERSION 3.29)
project(Transazioni_Finanziarie)

set(CMAKE_CXX_STANDARD 20)

# Main executable
add_executable(Transazioni_Finanziarie
        main.cpp
        Transaction.h Transaction.cpp
        BankAccount.h BankAccount.cpp
)

# Automatic Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Tests
enable_testing()

#Test files
set(TEST_SOURCES
        tests/test_of_transaction.cpp
        tests/test_of_bankaccount.cpp
)

# Executable for the tests
add_executable(runTests ${TEST_SOURCES}
        Transaction.h Transaction.cpp
        BankAccount.h BankAccount.cpp
)

# Link for Google Test
target_link_libraries(runTests PRIVATE gtest gtest_main)

# To register the tests
include(GoogleTest)
gtest_discover_tests(runTests)