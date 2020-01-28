//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

namespace fuzzy {

    #include "../core/Expression.h"
    #include "../core/BinaryExpression.h"
    #include "Operators.h"

    template<class T>
    class OrMax:public fuzzy::Or<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
    };

    template<class T>
    T OrMax<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const{
        return std::max(left->evaluate(),right->evaluate());
    }
}

#endif //FUZZY_ORMAX_H
