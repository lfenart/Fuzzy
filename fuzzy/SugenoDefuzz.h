//
// Created by Lucas Schloesslin on 06/03/2020.
//

#ifndef FUZZY_SUGENODEFUZZ_H
#define FUZZY_SUGENODEFUZZ_H

#include "../core/BinaryExpressionModel.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/Expression.h"
#include "../core/NaryExpression.h"
#include "SugenoThen.h"

namespace fuzzy {

template <class T>
class SugenoDefuzz : core::NaryExpression<T> {
public:
    T evaluate(std::vector<core::Expression<T>*>) const;
};

template <class T>
T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*> operands) const
{
    T num(0);
    T denum(0);
    for (typename std::vector<core::Expression<T>*>::iterator it = operands.begin(); it != operands.end(); it++) {
        core::BinaryExpressionModel<T>* op = (core::BinaryExpressionModel<T>*) *it;
        core::BinaryShadowExpression<T>* shadow = (core::BinaryShadowExpression<T>*) op->getOp();
        SugenoThen<T>* then = (SugenoThen<T>*) shadow->getTarget();
        T value = op->evaluate();
        T premise = then->premiseValue();
        num += value * premise;
        denum += premise;
    }
    if (denum == 0) {
        throw "Division by 0";
    }
    return num / denum;
}

}

#endif //FUZZY_SUGENODEFUZZ_H
