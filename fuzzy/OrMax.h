#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "Operators.h"

namespace fuzzy {

template <class T>
class OrMax : public fuzzy::Or<T> {
public:
    virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
};

template <class T>
T OrMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{
    T l = left->evaluate();
    T r = right->evaluate();

    return (l >= r) ? l : r;
}

}

#endif //FUZZY_ORMAX_H
