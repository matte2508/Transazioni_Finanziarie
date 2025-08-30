cmake_minimum_required(VERSION 3.29)
project(Transazioni_Finanziarie)

set(CMAKE_CXX_STANDARD 20)

add_executable(Transazioni_Finanziarie main.cpp
        Transaction.h
        BankAccount.h
        Transaction.cpp
        BankAccount.cpp)
