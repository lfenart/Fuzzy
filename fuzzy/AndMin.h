//
// Created by mac air on 28/01/2020.
//

#include "../core/Expression.h"
#include "operators.h"

#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H


namespace fuzzy {
    template<typename T>
    class AndMin : public And<T> {

    public:
        T evaluate(core::Expression<T> *left, core::Expression<T> *right) const override;
    };

    template<typename T>
    T AndMin<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {

        T l = left->evaluate();
        T r = right->evaluate();

        return (l <= r) ? l : r;
    }
}

#endif //FUZZY_ANDMIN_H
