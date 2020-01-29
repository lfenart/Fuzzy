//
// Created by xavie on 29/01/2020.
//

#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"

namespace core{
    template<class T>
    class UnaryShadowExpresssion : public UnaryExpression<T>{

    private:
        UnaryExpression <T> *target;

    public:
        UnaryShadowExpresssion(UnaryExpression <T> *);

        T evaluate(Expression <T> *) const ;

        UnaryExpression <T> *getTarget() const;

        void setTarget(UnaryExpression <T> *);
    };

    template<class T>
    UnaryShadowExpresssion<T>::UnaryShadowExpresssion(UnaryExpression <T> *_target) : target(_target) {
    }

    template<class T>
    T UnaryShadowExpresssion<T>::evaluate(Expression <T> *o) const {

        if (target == nullptr) {
            throw "target null";
        }

        return target->evaluate(o);
    }

    template<class T>
    UnaryExpression <T> *UnaryShadowExpresssion<T>::getTarget() const {
        return target;
    }

    template<class T>
    void UnaryShadowExpresssion<T>::setTarget(UnaryExpression <T> *_target) {
        target = _target;
    }
}
#endif //FUZZY_UNARYSHADOWEXPRESSION_H
