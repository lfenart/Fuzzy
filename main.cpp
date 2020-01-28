#include <iostream>

#include "core/ValueModel.h"
#include "core/BinaryExpression.h"
#include "core/BinaryExpressionModel.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/IsTriangle.h"

typedef double num_t;

int main() {
    core::ValueModel<num_t> v1(1);
    std::cout << v1.evaluate() << std::endl;

    core::ValueModel<num_t> v2;
    v2.setValue(5);
    std::cout << v2.evaluate() << std::endl;

    fuzzy::OrMax<num_t> orMax;
    std::cout << orMax.evaluate(&v1, &v2) << std::endl;

    fuzzy::OrPlus<num_t> orPlus;
    std::cout << orPlus.evaluate(&v1, &v2) << std::endl;

    fuzzy::AggMax<num_t> aggMax;
    std::cout << aggMax.evaluate(&v1, &v2) << std::endl;

    fuzzy::AggPlus<num_t> aggPlus;
    std::cout << aggPlus.evaluate(&v1, &v2) << std::endl;

    core::BinaryExpressionModel<num_t> binExp(&v1, &v2, &aggPlus);
    std::cout << binExp.evaluate() << std::endl;

    fuzzy::AndMin<num_t> andMin;
    std::cout << andMin.evaluate(&v1, &v2) << std::endl;

    fuzzy::AndMult<num_t> andMult;
    std::cout << andMult.evaluate(&v1, &v2) << std::endl;

    fuzzy::IsTriangle<num_t> isTriangle(2.5,5,7.5);
    std::cout << isTriangle.evaluate(&v2) << std::endl;

    return 0;
}
