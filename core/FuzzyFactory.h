//
// Created by Lucas Schloesslin on 29/01/2020.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "Expression.h"
#include "UnaryExpressionModel.h"

namespace core{

    template<class T>
    class FuzzyFactory : public ExpressionFactory<T>{
        public :
            FuzzyFactory();
            ~FuzzyFactory();
            Expression<T> *newAnd(Expression<T>*, Expression<T>*);
            Expression<T> *newOr(Expression<T>*, Expression<T>*);
            Expression<T> *newThen(Expression<T>*, Expression<T>*);
            Expression<T> *newAgg(Expression<T>*, Expression<T>*);
            UnaryExpressionModel<T> *newNot(Expression<T>*);
            //Expression<T> *newIs(, Expression<T>*);
    };

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(){

    }

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory(){

    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* left, Expression<T>* right){
        return nullptr;
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* left, Expression<T>* right){
        return nullptr;
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* left, Expression<T>* right){
        return nullptr;
    }

    template<class T>
    Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* left, Expression<T>* right){
        return nullptr;
    }

    template<class T>
    UnaryExpressionModel<T>* FuzzyFactory<T>::newNot(Expression<T>* expression){
        return nullptr;
    }

}

#endif //FUZZY_FUZZYFACTORY_H
