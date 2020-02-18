//
// Created by xavie on 28/01/2020.
//

#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H

#include "Operators.h"

namespace fuzzy {

template <class T>
class ThenMin : public fuzzy::Then<T> {
public:
    virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
};

template <class T>
T ThenMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{
    T l = left->evaluate();
    T r = right->evaluate();
    return (l <= r) ? l : r;
}

}
#endif //FUZZY_THENMIN_H
