//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"

namespace core {

    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T> {
    public:
        UnaryExpressionModel(Expression<T> *, UnaryExpression<T> *);

        T evaluate() const;

        T evaluate(Expression<T> *) const;

    private:
        Expression<T> *expression;
        UnaryExpression<T> *op;
    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(core::Expression<T> *_expression, core::UnaryExpression<T> *_op):expression(_expression),op(_op)
    {
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if (expression != nullptr) {
            return evaluate(expression);
        }
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T> *o) const {
        if(op != nullptr){
            return op->evaluate(o);
        }
    }

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H
