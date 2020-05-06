#include "../fuzzy/MamdaniDefuzz.h"

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
    FuzzyFactory(fuzzy::Not<T>*, fuzzy::And<T>*, fuzzy::Or<T>*, fuzzy::Then<T>*, fuzzy::Agg<T>*, fuzzy::Defuzz<T>*);
    virtual ~FuzzyFactory() {};

    Expression<T>* newAnd(Expression<T>*, Expression<T>*);
    Expression<T>* newOr(Expression<T>*, Expression<T>*);
    Expression<T>* newThen(Expression<T>*, Expression<T>*);
    Expression<T>* newAgg(Expression<T>*, Expression<T>*);
    Expression<T>* newNot(Expression<T>*);
    Expression<T>* newIs(fuzzy::Is<T>*, Expression<T>*);
    Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T&, const T&, const T&);

    void changeAnd(fuzzy::And<T>*);
    void changeOr(fuzzy::Or<T>*);
    void changeThen(fuzzy::Then<T>*);
    void changeAgg(fuzzy::Agg<T>*);
    void changeNot(fuzzy::Not<T>*);
    void changeDefuzz(fuzzy::MamdaniDefuzz<T>*);

private:
    BinaryShadowExpression<T> andShadow;
    BinaryShadowExpression<T> orShadow;
    BinaryShadowExpression<T> thenShadow;
    BinaryShadowExpression<T> aggShadow;
    UnaryShadowExpression<T> notShadow;
    BinaryShadowExpression<T> mamdaniShadow;
};

template <class T>
FuzzyFactory<T>::FuzzyFactory(fuzzy::Not<T>* _not, fuzzy::And<T>* _and, fuzzy::Or<T>* _or, fuzzy::Then<T>* _then, fuzzy::Agg<T>* _agg, fuzzy::Defuzz<T>* _defuzz)
    : andShadow(BinaryShadowExpression<T>(_and))
    , orShadow(BinaryShadowExpression<T>(_or))
    , thenShadow(BinaryShadowExpression<T>(_then))
    , aggShadow(BinaryShadowExpression<T>(_agg))
    , notShadow(UnaryShadowExpression<T>(_not))
    , mamdaniShadow(BinaryShadowExpression<T>(_defuzz))
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

template <typename T>
Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step)
{
    return this->newBinary(&mamdaniShadow, l, r);
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
template <class T>
void FuzzyFactory<T>::changeDefuzz(fuzzy::MamdaniDefuzz<T>* anMamdaniDefuzz)
{
    mamdaniShadow.setTarget(anMamdaniDefuzz);
}
}

#endif //FUZZY_FUZZYFACTORY_H
