//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

#include "Expression.h"

namespace core {

    template<class T>
    class UnaryExpression {
    public:
        virtual T evaluate(Expression<T>*) const = 0;
    };

}

#endif //FUZZY_UNARYEXPRESSION_H
