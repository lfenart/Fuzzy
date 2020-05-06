#ifndef FUZZY_ISTRAPEZOID_H
#define FUZZY_ISTRAPEZOID_H

#include "Operators.h"

namespace fuzzy {
template <typename T>
class IsTrapezoid : public Is<T> {
public:
    IsTrapezoid(const T&, const T&, const T&, const T&);
    virtual ~IsTrapezoid() {};

    T evaluate(core::Expression<T>*) const;

    const T& getMin() const;
    const T& getMidLeft() const;
    const T& getMidRight() const;
    const T& getMax() const;

    void setMin(const T&);
    void setMidLeft(const T&);
    void setMidRight(const T&);
    void setMax(const T&);

private:
    T min;
    T midLeft;
    T midRight;
    T max;
};

template <typename T>
IsTrapezoid<T>::IsTrapezoid(const T& _min, const T& _midLeft, const T& _midRight, const T& _max)
    : min(_min)
    , midLeft(_midLeft)
    , midRight(
          _midRight)
    , max(_max)
{
}

template <typename T>
T IsTrapezoid<T>::evaluate(core::Expression<T>* expression) const
{
    T value = expression->evaluate();
    if (value <= min) {
        return 0;
    } else if (value >= min && value <= midLeft) {
        return (value - min) / (midLeft - min);
    } else if (value >= midLeft && value <= midRight) {
        return 1;
    } else if (value >= midRight && value <= max) {
        return (max - value) / (max - midRight);
    }
    return 0;
}

template <typename T>
const T& IsTrapezoid<T>::getMin() const
{
    return min;
}

template <typename T>
const T& IsTrapezoid<T>::getMidLeft() const
{
    return midLeft;
}

template <typename T>
const T& IsTrapezoid<T>::getMidRight() const
{
    return midRight;
}

template <typename T>
const T& IsTrapezoid<T>::getMax() const
{
    return max;
}

template <typename T>
void IsTrapezoid<T>::setMin(const T& _min)
{
    min = _min;
}

template <typename T>
void IsTrapezoid<T>::setMidLeft(const T& _midLeft)
{
    midLeft = _midLeft;
}

template <typename T>
void IsTrapezoid<T>::setMidRight(const T& _midRight)
{
    midRight = _midRight;
}

template <typename T>
void IsTrapezoid<T>::setMax(const T& _max)
{
    max = _max;
}

}
#endif //FUZZY_ISTRAPEZOID_H
