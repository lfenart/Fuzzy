#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"
#include <iostream>

namespace core {

template <class T>
class BinaryShadowExpression : public BinaryExpression<T> {
public:
    BinaryShadowExpression(BinaryExpression<T>* _target);
    virtual ~BinaryShadowExpression() {};

    T evaluate(Expression<T>* left, Expression<T>* right) const;

    BinaryExpression<T>* getTarget() const;

    void setTarget(BinaryExpression<T>* _target);

private:
    BinaryExpression<T>* target;
};

template <class T>
BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target)
    : target(_target)
{
}

template <class T>
T BinaryShadowExpression<T>::evaluate(Expression<T>* left, Expression<T>* right) const
{

    if (target == nullptr) {
        throw "target null";
    }

    return target->evaluate(left, right);
}

template <class T>
BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() const
{
    return target;
}

template <class T>
void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* _target)
{
    target = _target;
}

}
#endif //FUZZY_BINARYSHADOWEXPRESSION_H
