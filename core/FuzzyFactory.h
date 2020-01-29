//
// Created by Lucas Schloesslin on 29/01/2020.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryShadowExpression.h"
#include "../fuzzy/Operators.h"

namespace core{

    template<class T>
    class FuzzyFactory : public ExpressionFactory<T>{
        private:
            BinaryShadowExpression<T> andShadow;
            BinaryShadowExpression<T> orShadow;
            BinaryShadowExpression<T> thenShadow;
            BinaryShadowExpression<T> aggShadow;
        public :
            FuzzyFactory(BinaryShadowExpression<T>*,BinaryShadowExpression<T>*,BinaryShadowExpression<T>*,BinaryShadowExpression<T>*);
            ~FuzzyFactory();
            Expression<T> *newAnd(Expression<T>*, Expression<T>*);
            Expression<T> *newOr(Expression<T>*, Expression<T>*);
            Expression<T> *newThen(Expression<T>*, Expression<T>*);
            Expression<T> *newAgg(Expression<T>*, Expression<T>*);
            Expression<T> *newNot(Expression<T>*);
            //Expression<T> *newIs(, Expression<T>*);

            void changeAnd(fuzzy::And<T> anAnd);
            void changeOr(fuzzy::Or<T> anOr);
            void changeThen(fuzzy::Then<T> aThen);
            void changeAgg(fuzzy::Agg<T> anAgg);

    };

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(BinaryShadowExpression<T>* _andShadow, BinaryShadowExpression<T>* _orShadow, BinaryShadowExpression<T>* _thenShadow, BinaryShadowExpression<T>* _aggShadow){
        andShadow(_andShadow);
        orShadow(_orShadow);
        thenShadow(_thenShadow);
        aggShadow(_aggShadow);
    }

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory(){

    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* left, Expression<T>* right){
        return newBinary(andShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* left, Expression<T>* right){
        return newBinary(orShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* left, Expression<T>* right){
        return newBinary(thenShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* left, Expression<T>* right){
        return newBinary(aggShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* expression){
        return nullptr;
    }

    template<class T>
    void FuzzyFactory<T>::changeAnd(fuzzy::And<T> anAnd){
        andShadow.setTarget(anAnd);
    }

    template<class T>
    void FuzzyFactory<T>::changeOr(fuzzy::Or<T> anOr){
        orShadow.setTarget(anOr);
    }

    template<class T>
    void FuzzyFactory<T>::changeThen(fuzzy::Then<T> aThen){
        thenShadow.setTarget(aThen);
    }

    template<class T>
    void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T> anAgg){
        aggShadow.setTarget(anAgg);
    }
}

#endif //FUZZY_FUZZYFACTORY_H
