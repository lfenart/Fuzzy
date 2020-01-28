#include <iostream>

#include "core/ValueModel.h"
#include "core/BinaryExpression.h"
#include "core/UnaryExpression.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"

int main() {
    core::ValueModel<int> v;
    v.setValue(1);
    core::ValueModel<int> v1;
    v1.setValue(5);
    fuzzy::OrMax<int> orMax;
    fuzzy::OrPlus<int> orPlus;
    std::cout << v.evaluate() << std::endl;
    std::cout << orMax.evaluate(&v,&v1) << std::endl;
    std::cout << orPlus.evaluate(&v,&v1) << std::endl;
    return 0;
}
