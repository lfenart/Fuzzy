//
// Created by lucasf on 18/02/2020.
//

#ifndef FUZZY_NARYEXPRESSION_H
#define FUZZY_NARYEXPRESSION_H

#include "Expression.h"

namespace core {

    template<class T>
    class NaryExpression {
    public:
        virtual T evaluate(Expression<T> *, Expression<T> *) const = 0;
    };

}

#endif //FUZZY_NARYEXPRESSION_H
