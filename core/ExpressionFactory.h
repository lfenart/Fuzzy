//
// Created by lucasf on 29/01/2020.
//

#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include <vector>

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"

namespace core {

    template<class T>
    class ExpressionFactory {
    public:
        ExpressionFactory();

        virtual ~ExpressionFactory();

        Expression <T> *hold(Expression <T> *);

        Expression <T> *newUnary(UnaryExpression <T> *, Expression <T> *);

        Expression <T> *newBinary(BinaryExpression <T> *, Expression <T> *, Expression <T> *);

    private:
        std::vector<Expression < T> *>
        memory;
    };

    template<class T>
    ExpressionFactory<T>::ExpressionFactory() {}

    template<class T>
    ExpressionFactory<T>::~ExpressionFactory() {
        for (typename std::vector<Expression<T> *>::iterator it = memory.begin(); it != memory.end(); it++) {
            delete *it;
        }
    }

    template<class T>
    Expression <T> *ExpressionFactory<T>::hold(Expression <T> *expression) {
        memory.push_back(expression);
        return expression;
    }

    template<class T>
    Expression <T> *ExpressionFactory<T>::newUnary(UnaryExpression <T> *ope, Expression <T> *o) {
        return new UnaryExpressionModel(ope, o);
    }

    template<class T>
    Expression <T> *ExpressionFactory<T>::newBinary(BinaryExpression <T> *ope, Expression <T> *l, Expression <T> *r) {
        return new BinaryExpressionModel(ope, l, r);
    }

}

#endif //FUZZY_EXPRESSIONFACTORY_H
