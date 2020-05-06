#ifndef FUZZY_AGGPLUS_H
#define FUZZY_AGGPLUS_H

#include "Operators.h"

namespace fuzzy {

template <class T>
class AggPlus : public fuzzy::Agg<T> {
public:
    T evaluate(core::Expression<T>*, core::Expression<T>*) const;
};

template <class T>
T AggPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{
    T l = left->evaluate();
    T r = right->evaluate();
    T result = l + r;
    return (result > 1) ? 1 : result;
}

}

#endif //FUZZY_AGGPLUS_H
