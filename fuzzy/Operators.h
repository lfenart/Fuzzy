//
// Created by mac air on 28/01/2020.
//

#ifndef FUZZY_OPERATORS_H
#define FUZZY_OPERATORS_H


#include "../core/Expression.h"
#include "../core/BinaryExpression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy {


    template<typename T>
    class And : public core::BinaryExpression<T> {
    public:
        virtual ~And() {};
    };
    template<typename T>
    class Is : public core::UnaryExpression<T> {
    public:
        virtual ~Is() {};
    };

    template<class T>
    class Or : public core::BinaryExpression<T> {
    public:
        virtual ~Or() {};
    };

    template<class T>
    class Then : public core::BinaryExpression<T>{
    };

    template<class T>
    class Agg : public core::BinaryExpression<T> {
    public:
        virtual ~Agg() {};
    };

    template<class T>
    class Not : public core::UnaryExpression<T> {
    public:
        virtual ~Not() {};
    };
}


#endif //FUZZY_OPERATORS_H
