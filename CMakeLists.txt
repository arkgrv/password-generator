cmake_minimum_required(VERSION 3.10)
project (password-generator CXX)

set(SOURCES PasswordGenerator.h PasswordGenerator.cpp Password.cpp)
add_executable(password-generator ${SOURCES})
