#include <iostream>

#include "core/ValueModel.h"
#include "core/BinaryExpression.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"

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

    return 0;
}
