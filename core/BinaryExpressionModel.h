//
// Created by lucasf on 28/01/2020.
//

#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"

namespace core {

    template<class T>
    class BinaryExpressionModel : public BinaryExpression<T> {
    public:
        BinaryExpressionModel(Expression<T> *, Expression<T> *, BinaryExpression<T> *);

        T evaluate() const;

        T evaluate(Expression<T> *, Expression<T> *) const;

    private:
        Expression<T> *left;
        Expression<T> *right;
        BinaryExpression<T> *op;
    };

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(core::Expression<T> *_left, core::Expression<T> *_right,
                                                    core::BinaryExpression<T> *_op): left(_left), right(_right),
                                                                                     op(_op) {}

    template<class T>
    T BinaryExpressionModel<T>::evaluate() const {
        if (left != nullptr && right != nullptr) {
            return evaluate(left, right);
        }
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
        return op->evaluate(left, right);
    }

}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
