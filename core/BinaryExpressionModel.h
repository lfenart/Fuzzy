#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"

namespace core {

template <class T>
class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
public:
    BinaryExpressionModel(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
    virtual ~BinaryExpressionModel() {};

    T evaluate() const;
    T evaluate(Expression<T>*, Expression<T>*) const;

    BinaryExpression<T>* getOp() const;

private:
    BinaryExpression<T>* op;
    Expression<T>* left;
    Expression<T>* right;
};

template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _op, Expression<T>* _left,
    Expression<T>* _right)
    : op(_op)
    , left(_left)
    , right(_right)
{
}

template <class T>
T BinaryExpressionModel<T>::evaluate() const
{
    if (left != nullptr && right != nullptr) {
        return evaluate(left, right);
    }
    throw "";
}

template <class T>
T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
{
    if (op != nullptr) {
        return op->evaluate(l, r);
    }
    throw "";
}

template <class T>
BinaryExpression<T>* BinaryExpressionModel<T>::getOp() const
{
    return op;
}

}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
