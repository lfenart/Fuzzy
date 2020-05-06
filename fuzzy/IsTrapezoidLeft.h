#ifndef FUZZY_ISTRAPEZOIDLEFT_H
#define FUZZY_ISTRAPEZOIDLEFT_H

#include "Operators.h"

namespace fuzzy {
template <typename T>
class IsTrapezoidLeft : public Is<T> {
public:
    IsTrapezoidLeft(const T&, const T&);
    virtual ~IsTrapezoidLeft() {};

    T evaluate(core::Expression<T>*) const;

    const T& getMin() const;
    const T& getMax() const;

    void setMin(const T&);
    void setMax(const T&);

private:
    T min;
    T max;
};

template <typename T>
IsTrapezoidLeft<T>::IsTrapezoidLeft(const T& _min, const T& _max)
    : min(_min)
    , max(_max)
{
}

template <typename T>
T IsTrapezoidLeft<T>::evaluate(core::Expression<T>* expression) const
{
    T value = expression->evaluate();
    if (value <= min) {
        return 1;
    } else if (value >= min && value <= max) {
        return (max - value) / (max - min);
    } else if (value >= max) {
        return 0;
    }
    return 0;
}

template <typename T>
const T& IsTrapezoidLeft<T>::getMin() const
{
    return min;
}

template <typename T>
const T& IsTrapezoidLeft<T>::getMax() const
{
    return max;
}

template <typename T>
void IsTrapezoidLeft<T>::setMin(const T& _min)
{
    min = _min;
}

template <typename T>
void IsTrapezoidLeft<T>::setMax(const T& _max)
{
    max = _max;
}
}

#endif //FUZZY_ISTRAPEZOIDLEFT_H
