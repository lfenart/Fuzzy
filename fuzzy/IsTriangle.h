#ifndef FUZZY_ISTRIANGLE_H
#define FUZZY_ISTRIANGLE_H

#include "Operators.h"

namespace fuzzy {

template <typename T>
class IsTriangle : public Is<T> {
public:
    IsTriangle(const T&, const T&, const T&);
    virtual ~IsTriangle() {};

    T evaluate(core::Expression<T>*) const;

    const T& getMin() const;
    const T& getMid() const;
    const T& getMax() const;

    void setMin(const T&);
    void setMid(const T&);
    void setMax(const T&);

private:
    T min;
    T mid;
    T max;
};

template <typename T>
IsTriangle<T>::IsTriangle(const T& _min, const T& _mid, const T& _max)
    : min(_min)
    , mid(_mid)
    , max(_max)
{
}

template <typename T>
T IsTriangle<T>::evaluate(core::Expression<T>* expression) const
{
    T value = expression->evaluate();
    if (value <= min) {
        return 0;
    } else if (value >= min && value <= mid) {
        return (value - min) / (mid - min);
    } else if (value >= mid && value <= max) {
        return (max - value) / (max - mid);
    }
    return 0;
}

template <typename T>
const T& IsTriangle<T>::getMin() const
{
    return min;
}

template <typename T>
const T& IsTriangle<T>::getMid() const
{
    return mid;
}

template <typename T>
const T& IsTriangle<T>::getMax() const
{
    return max;
}

template <typename T>
void IsTriangle<T>::setMin(const T& _min)
{
    min = _min;
}

template <typename T>
void IsTriangle<T>::setMid(const T& _mid)
{
    mid = _mid;
}

template <typename T>
void IsTriangle<T>::setMax(const T& _max)
{
    max = _max;
}

}

#endif //FUZZY_ISTRIANGLE_H
