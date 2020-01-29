#include <iostream>

#include "core/ValueModel.h"
#include "core/BinaryExpression.h"
#include "core/BinaryExpressionModel.h"
#include "core/UnaryExpressionModel.h"
#include "core/UnaryExpression.h"
#include "core/ExpressionFactory.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/NotMinus1.h"

typedef double num_t;

int main() {
    // TODO: rewrite
    
    core::ValueModel<num_t> v1(3);
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

    core::BinaryExpressionModel<num_t> binExp(new fuzzy::AggPlus<num_t>(), new core::ValueModel<num_t>(0.1),
                                              new core::ValueModel<num_t>(10));
    std::cout << binExp.evaluate() << std::endl;

    core::UnaryExpressionModel<num_t> unExp(new fuzzy::IsTriangle<num_t>(2, 4, 6), new core::ValueModel<num_t>(2));
    std::cout << unExp.evaluate() << std::endl;
    fuzzy::AndMin<num_t> andMin;
    std::cout << andMin.evaluate(&v1, &v2) << std::endl;

    fuzzy::AndMult<num_t> andMult;
    std::cout << andMult.evaluate(&v1, &v2) << std::endl;

    core::ExpressionFactory<num_t> factory;
    factory.hold(factory.newUnary(new fuzzy::NotMinus1<num_t>(), new core::ValueModel<num_t>(10)));

    return 0;
}
