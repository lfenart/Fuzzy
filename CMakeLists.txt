cmake_minimum_required(VERSION 3.15)
project(fuzzy)

set(CMAKE_CXX_STANDARD 17)

add_executable(fuzzy main.cpp core/Expression.h core/ValueModel.h core/UnaryExpression.h core/BinaryExpression.h fuzzy/Operators.h fuzzy/OrMax.h fuzzy/OrPlus.h)