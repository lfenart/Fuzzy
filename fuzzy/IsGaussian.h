#ifndef FUZZY_ISGAUSSIAN_H
#define FUZZY_ISGAUSSIAN_H

#include "Operators.h"
#include <cmath>

namespace fuzzy {

template <typename T>
class IsGaussian : public Is<T> {
public:
    IsGaussian(const T&, const T&);

    virtual ~IsGaussian() {};

    T evaluate(core::Expression<T>* expression) const;

private:
    T mean;
    T deviation;
};

template <typename T>
IsGaussian<T>::IsGaussian(const T& _mean, const T& _deviation)
    : mean(_mean)
    , deviation(_deviation)
{
}

template <typename T>
T IsGaussian<T>::evaluate(core::Expression<T>* expression) const
{
    T value = expression->evaluate();
    return exp(-0.5 * pow((value - mean) / deviation, 2));
}

}

#endif //FUZZY_ISGAUSSIAN_H
