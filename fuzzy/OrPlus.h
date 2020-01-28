//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_ORPLUS_H
#define FUZZY_ORPLUS_H

namespace fuzzy {

#include "../core/Expression.h"
    #include "../core/BinaryExpression.h"
    #include "Operators.h"

    template<class T>
    class OrPlus:public fuzzy::Or<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
    };

    template<class T>
    T OrPlus<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const{
        return left->evaluate()+right->evaluate();
    }
}


#endif //FUZZY_ORPLUS_H
