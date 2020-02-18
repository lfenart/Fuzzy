//
// Created by lucasf on 28/01/2020.
//

#ifndef FUZZY_AGGMAX_H
#define FUZZY_AGGMAX_H

#include "Operators.h"

namespace fuzzy {

template <class T>
class AggMax : public fuzzy::Agg<T> {
public:
    T evaluate(core::Expression<T>*, core::Expression<T>*) const;
};

template <class T>
T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{
    T l = left->evaluate();
    T r = right->evaluate();

    return (l > r) ? l : r;
}

}

#endif //FUZZY_AGGMAX_H
