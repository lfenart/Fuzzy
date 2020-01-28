//
// Created by mac air on 28/01/2020.
//

#ifndef FUZZY_OPERATORS_H
#define FUZZY_OPERATORS_H


#include "../core/Expression.h"
#include "../core/BinaryExpression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy {


    template<typename T>
    class And : public core::BinaryExpression<T> {

    public:
        virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const = 0;


    };
    template<typename T>
    class Is : public core::UnaryExpression<T> {

    public:
        virtual T evaluate(core::Expression<T> *expression) const = 0;
    };


}


#endif //FUZZY_OPERATORS_H
