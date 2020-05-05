
#ifndef FUZZY_SUGENOTHEN_H
#define FUZZY_SUGENOTHEN_H

#include "Operators.h"

namespace fuzzy {

template <class T>
class SugenoThen : public Then<T> {
public:
    T evaluate(core::Expression<T>*, core::Expression<T>*) const;
    T premiseValue() const;

private:
    mutable T premise;
};

template <class T>
T SugenoThen<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
{
    premise = l->evaluate();
    return premise * r->evaluate();
}

template <class T>
T SugenoThen<T>::premiseValue() const
{
    return premise;
}

}

#endif //FUZZY_SUGENOTHEN_H
