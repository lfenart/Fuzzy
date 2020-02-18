//
// Created by lucasf on 18/02/2020.
//

#ifndef FUZZY_NARYEXPRESSIONMODEL_H
#define FUZZY_NARYEXPRESSIONMODEL_H

#include <vector>

#include "Expression.h"
#include "NaryExpression.h"

namespace core {

template <class T>
class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
public:
    NaryExpressionModel(NaryExpression<T>*, std::vector<Expression<T>*>);

    virtual ~NaryExpressionModel() {};

    T evaluate() const;

    T evaluate(const std::vector<Expression<T>*>&) const;

private:
    NaryExpression<T>* ope;
    typename std::vector<Expression<T>*> operands;
};

template <class T>
NaryExpressionModel<T>::NaryExpressionModel(
    NaryExpression<T>* _ope,
    std::vector<Expression<T>*> _operands)
    : ope(_ope)
    , operands(_operands)
{
}

template <class T>
T NaryExpressionModel<T>::evaluate() const
{
    if (ope == nullptr) {
        throw "";
    }
    return evaluate(operands);
}

template <class T>
T NaryExpressionModel<T>::evaluate(
    const std::vector<Expression<T>*>& operands) const
{
    if (operands.size() == 0) {
        throw "";
    }
    return ope->evaluate(operands);
}

} // namespace core

#endif // FUZZY_NARYEXPRESSIONMODEL_H
