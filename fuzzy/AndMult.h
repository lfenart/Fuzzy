#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H

#include "../core/Expression.h"
#include "Operators.h"

namespace fuzzy {

template <typename T>
class AndMult : public And<T> {
public:
    T evaluate(core::Expression<T>* left, core::Expression<T>* right) const override;
};

template <typename T>
T AndMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{

    T leftValue = left->evaluate();
    T rightValue = right->evaluate();

    return leftValue * rightValue;
}

}
#endif //FUZZY_ANDMULT_H
