cmake_minimum_required(VERSION 3.20)
project(BigIntegerUseVector)

set(CMAKE_CXX_STANDARD 14)

add_executable(BigInteger main.cpp BigInteger.cpp Constructor.cpp OringeOperatorFunction.cpp Operators.cpp  mutable/MutableBigInteger.cpp mutable/Arrays.h mutable/IntegerHelp.h)
