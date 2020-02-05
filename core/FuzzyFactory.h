//
// Created by Lucas Schloesslin on 29/01/2020.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryShadowExpression.h"
#include "UnaryShadowExpression.h"
#include "../fuzzy/Operators.h"

namespace core{

    template<class T>
    class FuzzyFactory : public ExpressionFactory<T>{
        private:
            BinaryShadowExpression<T> andShadow;
            BinaryShadowExpression<T> orShadow;
            BinaryShadowExpression<T> thenShadow;
            BinaryShadowExpression<T> aggShadow;
            UnaryShadowExpresssion<T> notShadow;
        public :
            FuzzyFactory(BinaryShadowExpression<T>*,BinaryShadowExpression<T>*,BinaryShadowExpression<T>*,BinaryShadowExpression<T>*, UnaryShadowExpresssion<T>*);
            ~FuzzyFactory();
            Expression<T> *newAnd(Expression<T>*, Expression<T>*);
            Expression<T> *newOr(Expression<T>*, Expression<T>*);
            Expression<T> *newThen(Expression<T>*, Expression<T>*);
            Expression<T> *newAgg(Expression<T>*, Expression<T>*);
            Expression<T> *newNot(Expression<T>*);
            Expression<T> *newIs(fuzzy::Is<T>*, Expression<T>*);

            void changeAnd(fuzzy::And<T> *anAnd);
            void changeOr(fuzzy::Or<T> *anOr);
            void changeThen(fuzzy::Then<T> *aThen);
            void changeAgg(fuzzy::Agg<T> *anAgg);
            void changeNot(fuzzy::Not<T> *aNot);
    };

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(BinaryShadowExpression<T>* _andShadow, BinaryShadowExpression<T>* _orShadow, BinaryShadowExpression<T>* _thenShadow, BinaryShadowExpression<T>* _aggShadow, UnaryShadowExpresssion<T>* _notShadow){
        andShadow(_andShadow);
        orShadow(_orShadow);
        thenShadow(_thenShadow);
        aggShadow(_aggShadow);
        notShadow(_notShadow);
    }

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory(){

    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* left, Expression<T>* right){
        return newBinary(&andShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* left, Expression<T>* right){
        return newBinary(&orShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* left, Expression<T>* right){
        return newBinary(&thenShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* left, Expression<T>* right){
        return newBinary(&aggShadow, left, right);
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* expression){
        return newUnary(&notShadow, expression);
    }

    template<class T>
    Expression<T> * FuzzyFactory<T>::newIs(fuzzy::Is<T>* anIs, Expression<T>* expression){
        return newUnary(anIs, expression);
    }


    template<class T>
    void FuzzyFactory<T>::changeAnd(fuzzy::And<T> *anAnd){
        andShadow.setTarget(anAnd);
    }

    template<class T>
    void FuzzyFactory<T>::changeOr(fuzzy::Or<T> *anOr){
        orShadow.setTarget(anOr);
    }

    template<class T>
    void FuzzyFactory<T>::changeThen(fuzzy::Then<T> *aThen){
        thenShadow.setTarget(aThen);
    }

    template<class T>
    void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T> *anAgg){
        aggShadow.setTarget(anAgg);
    }

    template<class T>
    void FuzzyFactory<T>::changeNot(fuzzy::Not<T> *aNot){
        notShadow.setTarget(aNot);
    }

}

#endif //FUZZY_FUZZYFACTORY_H
