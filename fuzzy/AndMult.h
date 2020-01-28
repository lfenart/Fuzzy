//
// Created by mac air on 28/01/2020.
//

#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {


    template<typename T>
    class AndMult : public And<T> {

    public:
        T evaluate(core::Expression<T> *left, core::Expression<T> *right) const override;
    };

    template<typename T>
    T AndMult<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {

        T leftValue = left->evaluate();
        T rightValue = right->evaluate();

        return leftValue * rightValue;
    }
}
#endif //FUZZY_ANDMULT_H