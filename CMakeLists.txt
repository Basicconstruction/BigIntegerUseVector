cmake_minimum_required(VERSION 3.20)
project(BigIntegerUseVector)

set(CMAKE_CXX_STANDARD 14)

add_executable(BigIntegerUseVector main.cpp BigInteger.h BigInteger.cpp Utils.h Utils.cpp Constructor.cpp OringeOperatorFunction.cpp Operators.cpp)
