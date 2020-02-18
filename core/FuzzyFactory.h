//
// Created by Lucas Schloesslin on 29/01/2020.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "../fuzzy/Operators.h"
#include "BinaryShadowExpression.h"
#include "Expression.h"
#include "ExpressionFactory.h"
#include "UnaryExpressionModel.h"
#include "UnaryShadowExpression.h"

namespace core {

template <class T>
class FuzzyFactory : public ExpressionFactory<T> {
public:
    FuzzyFactory(fuzzy::And<T>*, fuzzy::Or<T>*, fuzzy::Then<T>*, fuzzy::Agg<T>*, fuzzy::Not<T>*);

    virtual ~FuzzyFactory() {};

    Expression<T>* newAnd(Expression<T>*, Expression<T>*);

    Expression<T>* newOr(Expression<T>*, Expression<T>*);

    Expression<T>* newThen(Expression<T>*, Expression<T>*);

    Expression<T>* newAgg(Expression<T>*, Expression<T>*);

    Expression<T>* newNot(Expression<T>*);

    Expression<T>* newIs(fuzzy::Is<T>*, Expression<T>*);

    void changeAnd(fuzzy::And<T>* anAnd);

    void changeOr(fuzzy::Or<T>* anOr);

    void changeThen(fuzzy::Then<T>* aThen);

    void changeAgg(fuzzy::Agg<T>* anAgg);

    void changeNot(fuzzy::Not<T>* aNot);

private:
    BinaryShadowExpression<T> andShadow;
    BinaryShadowExpression<T> orShadow;
    BinaryShadowExpression<T> thenShadow;
    BinaryShadowExpression<T> aggShadow;
    UnaryShadowExpression<T> notShadow;
};

template <class T>
FuzzyFactory<T>::FuzzyFactory(fuzzy::And<T>* _and, fuzzy::Or<T>* _or, fuzzy::Then<T>* _then, fuzzy::Agg<T>* _agg,
    fuzzy::Not<T>* _not)
    : andShadow(BinaryShadowExpression<T>(_and))
    , orShadow(BinaryShadowExpression<T>(_or))
    , thenShadow(BinaryShadowExpression<T>(_then))
    , aggShadow(BinaryShadowExpression<T>(_agg))
    , notShadow(UnaryShadowExpression<T>(_not))
{
}

template <class T>
Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* left, Expression<T>* right)
{
    return this->newBinary(&andShadow, left, right);
}

template <class T>
Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* left, Expression<T>* right)
{
    return this->newBinary(&orShadow, left, right);
}

template <class T>
Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* left, Expression<T>* right)
{
    return this->newBinary(&thenShadow, left, right);
}

template <class T>
Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* left, Expression<T>* right)
{
    return this->newBinary(&aggShadow, left, right);
}

template <class T>
Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* expression)
{
    return this->newUnary(&notShadow, expression);
}

template <class T>
Expression<T>* FuzzyFactory<T>::newIs(fuzzy::Is<T>* anIs, Expression<T>* expression)
{
    return this->newUnary(anIs, expression);
}

template <class T>
void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* anAnd)
{
    andShadow.setTarget(anAnd);
}

template <class T>
void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* anOr)
{
    orShadow.setTarget(anOr);
}

template <class T>
void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* aThen)
{
    thenShadow.setTarget(aThen);
}

template <class T>
void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* anAgg)
{
    aggShadow.setTarget(anAgg);
}

template <class T>
void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* aNot)
{
    notShadow.setTarget(aNot);
}

}

#endif //FUZZY_FUZZYFACTORY_H
