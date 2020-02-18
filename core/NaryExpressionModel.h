//
// Created by lucasf on 18/02/2020.
//

#ifndef FUZZY_NARYEXPRESSIONMODEL_H
#define FUZZY_NARYEXPRESSIONMODEL_H

#include <vector>
#include "NaryExpression.h"
#include "Expression.h"

namespace core {

    template<class T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
    public:
        NaryExpressionModel(std::vector<NaryExpression<T> *>);

        virtual ~NaryExpressionModel();

        T evaluate() const;

        T evaluate(const std::vector<Expression<T> *> &) const;

    private:
        NaryExpression<T> *op;
        std::vector<Expression<T> *> operands;
    };

    template<class T>
    NaryExpressionModel<T>::NaryExpressionModel(std::vector<NaryExpression<T> *> _operands): operands(_operands) {}

    template<class T>
    NaryExpressionModel<T>::~NaryExpressionModel() {
//        for (typename std::vector<Expression<T> *>::iterator it = operands.begin(); it != operands.end(); it++) {
//            delete *it;
//        }
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate() const {
        if (op != nullptr) {
            return evaluate(operands);
        }
        throw "";
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(const std::vector<Expression<T> *> &operands) const {
        if (operands.size() != 0) {
            return op->evaluate(operands);
        }
        throw "";
    }

}

#endif //FUZZY_NARYEXPRESSIONMODEL_H
