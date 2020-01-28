//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_OPERATORS_H
#define FUZZY_OPERATORS_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"

namespace fuzzy{

    template<class T>
    class Or:public core::BinaryExpression<T>{
        public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const = 0;
    };
}

#endif //FUZZY_OPERATORS_H
