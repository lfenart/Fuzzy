#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include "Expression.h"
#include "NaryExpression.h"
#include <vector>

namespace core {

template <class T>
class NaryShadowExpression : public NaryExpression<T> {
public:
    NaryShadowExpression(NaryExpression<T>*);
    virtual ~NaryShadowExpression() {};

    T evaluate(std::vector<Expression<T>*>) const;

    void setTarget(NaryExpression<T>*);

private:
    NaryExpression<T>* target;
};

template <class T>
NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* _target)
    : target(_target)
{
}

template <class T>
T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*> operands) const
{
    target->evaluate(operands);
}

template <class T>
void NaryShadowExpression<T>::setTarget(NaryExpression<T>* _target)
{
    target = _target;
}

}

#endif //FUZZY_NARYSHADOWEXPRESSION_H
