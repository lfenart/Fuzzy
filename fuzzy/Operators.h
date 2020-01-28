//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_OPERATORS_H
#define FUZZY_OPERATORS_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"

namespace fuzzy {

    template<class T>
    class Or : public core::BinaryExpression<T> {
    };

    template<class T>
    class Agg : core::BinaryExpression<T> {
    };

}

#endif //FUZZY_OPERATORS_H
