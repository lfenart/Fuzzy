#ifndef OPERATOR_H
#define OPERATOR_H
#include "Expression.h"
#include "BinaryExpression.h"

namespace fuzzy {


    template<typename T>
    class And : public core::BinaryExpression<T> {

    public:
        virtual T evaluate(core::Expression <T> *left, core::Expression <T> *right) const = 0;
    };


}

#endif