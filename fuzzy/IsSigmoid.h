
#ifndef FUZZY_ISSIGMOID_H
#define FUZZY_ISSIGMOID_H
#include <cmath>

#include "Operators.h"

namespace fuzzy {

template <typename T>
class IsSigmoid : public Is<T> {
public:
    IsSigmoid(const T& _mid);

    T evaluate(core::Expression<T>* expression) const;

private:
    T mid;
};

template <typename T>
IsSigmoid<T>::IsSigmoid(const T& _mid)
    : mid(_mid)
{
}

template <typename T>
T IsSigmoid<T>::evaluate(core::Expression<T>* expression) const
{

    return 1 / (1 + std::exp(-expression->evaluate() + mid));
}

}

#endif //FUZZY_ISSIGMOID_H
