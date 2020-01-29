//
// Created by mac air on 29/01/2020.
//

#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include <iostream>
#include "BinaryExpression.h"
namespace core {
    template<class T>
    class BinaryShadowExpression : public BinaryExpression<T> {

    private:
        BinaryExpression <T> *target;

    public:
        BinaryShadowExpression(BinaryExpression <T> *_target);

        T evaluate(Expression <T> *left, Expression <T> *right) const ;

        BinaryExpression <T> *getTarget() const;

        BinaryExpression <T> *getTarget();

        void setTarget(BinaryExpression <T> *_target);
    };

    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression <T> *_target) : target(_target) {
    }

    template<class T>
    T BinaryShadowExpression<T>::evaluate(Expression <T> *left, Expression <T> *right) const {

        if (target == nullptr) {
            std::cout << "nullptr" << std::endl;
        }

        return target->evaluate(left, right);
    }

    template<class T>
    BinaryExpression <T> *BinaryShadowExpression<T>::getTarget() const {
        return target;
    }

    template<class T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression <T> *_target) {
        target = _target;
    }

  
}
#endif //FUZZY_BINARYSHADOWEXPRESSION_H
