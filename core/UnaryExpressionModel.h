
#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"

namespace core {

template <class T>
class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T> {
public:
    UnaryExpressionModel(UnaryExpression<T>*, Expression<T>*);

    virtual ~UnaryExpressionModel() {};

    T evaluate() const;

    T evaluate(Expression<T>*) const;

private:
    UnaryExpression<T>* op;
    Expression<T>* expression;
};

template <class T>
UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _op, Expression<T>* _expression)
    : op(_op)
    , expression(_expression)
{
}

template <class T>
T UnaryExpressionModel<T>::evaluate() const
{
    if (expression != nullptr) {
        return evaluate(expression);
    }
    throw "";
}

template <class T>
T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
{
    if (op != nullptr) {
        return op->evaluate(o);
    }
    throw "";
}

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H
