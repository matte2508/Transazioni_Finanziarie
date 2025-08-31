find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(TEST_FILES
        test_of_transaction.cpp
        test_of_bankaccount.cpp
)

add_executable(runAllTests test_of_transaction.cpp test_of_bankaccount.cpp)
target_include_directories(runAllTests PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(runAllTests
        GTest::gtest #Google test's library
        GTest::gtest_main # Implement the function main for the tests
        core #Contains the main code
)