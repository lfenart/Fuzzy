//
// Created by xavie on 29/01/2020.
//

#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"

namespace core {
template <class T>
class UnaryShadowExpression : public UnaryExpression<T> {

private:
    UnaryExpression<T>* target;

public:
    UnaryShadowExpression(UnaryExpression<T>*);

    T evaluate(Expression<T>*) const;

    UnaryExpression<T>* getTarget() const;

    void setTarget(UnaryExpression<T>*);
};

template <class T>
UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target)
    : target(_target)
{
}

template <class T>
T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const
{

    if (target == nullptr) {
        throw "target null";
    }

    return target->evaluate(o);
}

template <class T>
UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const
{
    return target;
}

template <class T>
void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* _target)
{
    target = _target;
}

}
#endif //FUZZY_UNARYSHADOWEXPRESSION_H
