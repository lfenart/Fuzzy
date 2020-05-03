cmake_minimum_required(VERSION 3.15)
project(fuzzy)

set(CMAKE_CXX_STANDARD 17)

add_executable(fuzzy main.cpp core/Expression.h core/ValueModel.h core/UnaryExpression.h core/BinaryExpression.h fuzzy/Operators.h fuzzy/OrMax.h fuzzy/OrPlus.h fuzzy/ThenMin.h fuzzy/ThenMult.h fuzzy/AggMax.h fuzzy/AggPlus.h core/BinaryExpressionModel.h fuzzy/AndMin.h fuzzy/AndMult.h fuzzy/IsTriangle.h core/UnaryExpressionModel.h fuzzy/NotMinus1.h core/ExpressionFactory.h core/FuzzyFactory.h core/BinaryShadowExpression.h core/UnaryShadowExpression.h fuzzy/IsGaussian.h fuzzy/IsSigmoid.h core/NaryExpression.h core/NaryExpressionModel.h core/NaryShadowExpression.h fuzzy/SugenoDefuzz.h fuzzy/SugenoConclusion.h fuzzy/MamdaniDefuzz.h fuzzy/CogDefuzz.h fuzzy/Shape.h)
