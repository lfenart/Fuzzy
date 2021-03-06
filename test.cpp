#include <cassert>
#include <cstring>
#include <iostream>

#include "core/FuzzyFactory.h"
#include "core/ValueModel.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/IsGaussian.h"
#include "fuzzy/IsSigmoid.h"
#include "fuzzy/IsTrapezoid.h"
#include "fuzzy/IsTrapezoidLeft.h"
#include "fuzzy/IsTrapezoidRight.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/SugenoDefuzz.h"
#include "fuzzy/SugenoThen.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/ThenMult.h"

#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

typedef double num_t;

fuzzy::AndMin<num_t> andMin;
fuzzy::AndMult<num_t> andMult;
fuzzy::OrMax<num_t> orMax;
fuzzy::OrPlus<num_t> orPlus;
fuzzy::ThenMin<num_t> thenMin;
fuzzy::ThenMult<num_t> thenMult;
fuzzy::AggMax<num_t> aggMax;
fuzzy::AggPlus<num_t> aggPlus;
fuzzy::NotMinus1<num_t> notMinus1;
fuzzy::CogDefuzz<num_t> opDefuzz;
fuzzy::IsGaussian<num_t> isGaussian(0.5, 0.1);
fuzzy::IsSigmoid<num_t> isSigmoid(0.5);
fuzzy::IsTriangle<num_t> isTriangle(0.2, 0.5, 0.8);

void testCogDefuzz(core::FuzzyFactory<num_t>* factory)
{

    fuzzy::IsTriangle<num_t> poor(-5, 0, 5);
    fuzzy::IsTriangle<num_t> good(0, 5, 10);
    fuzzy::IsTriangle<num_t> excellent(5, 10, 15);

    fuzzy::IsTriangle<num_t> cheap(0, 5, 10);
    fuzzy::IsTriangle<num_t> average(10, 15, 20);
    fuzzy::IsTriangle<num_t> generous(20, 25, 30);

    fuzzy::IsTriangle<num_t> rancid(-5, 0, 5);
    fuzzy::IsTriangle<num_t> delicious(5, 10, 15);

    core::ValueModel<num_t> service(0);
    core::ValueModel<num_t> food(0);
    core::ValueModel<num_t> tips(0);
    //core::Expression<num_t> *r = factory->newAgg(factory->newAgg(factory->newThen(factory->newIs(&poor,&service),factory->newIs(&cheap,&tips)),factory->newThen(factory->newIs(&good,&service),factory->newIs(&average,&tips))),factory->newThen(factory->newIs(&excellent,&service),factory->newIs(&generous,&tips)));
    core::Expression<num_t>* r = factory->newAgg(
        factory->newAgg(
            factory->newThen(
                factory->newOr(
                    factory->newIs(&poor, &service),
                    factory->newIs(&rancid, &food)),
                factory->newIs(&cheap, &tips)),
            factory->newThen(
                factory->newIs(&good, &service),
                factory->newIs(&average, &tips))),

        factory->newThen(
            factory->newOr(
                factory->newIs(&excellent, &service),
                factory->newIs(&delicious, &food)),
            factory->newIs(&generous, &tips)));
    core::Expression<num_t>* system = factory->newDefuzz(&tips, r, 0, 25, 1);

    double s;
    while (true) {
        std::cout << "service : " << std::endl;
        std::cin >> s;
        std::cin.get();

        service.setValue(s);
        std::cout << "food : " << std::endl;
        std::cin >> s;
        std::cin.get();

        food.setValue(s);

        std::cout << "tips->" << system->evaluate() << std::endl;
        //std::cin.get();
    }
}

void testValueModel()
{
    num_t value1 = 0.2;
    num_t value2 = 0.8;

    core::ValueModel<num_t> v1(value1);
    assert(value1 == v1.evaluate());

    v1.setValue(value2);
    assert(value2 == v1.evaluate());
}

void testAndMin(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeAnd(&andMin);
    core::Expression<num_t>* myAnd = factory->newAnd(&v1, &v2);
    assert(min(value1, value2) == myAnd->evaluate());
}

void testAndMult(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeAnd(&andMult);
    core::Expression<num_t>* myAnd = factory->newAnd(&v1, &v2);
    assert(value1 * value2 == myAnd->evaluate());
}

void testOrMax(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeOr(&orMax);
    core::Expression<num_t>* myOr = factory->newOr(&v1, &v2);
    assert(max(value1, value2) == myOr->evaluate());
}

void testOrPlus(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeOr(&orPlus);
    core::Expression<num_t>* myOr = factory->newOr(&v1, &v2);
    assert(max(0, min(1, value1 + value2)) == myOr->evaluate());
}

void testThenMin(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeThen(&thenMin);
    core::Expression<num_t>* myThen = factory->newThen(&v1, &v2);
    assert(min(value1, value2) == myThen->evaluate());
}

void testThenMult(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeThen(&thenMult);
    core::Expression<num_t>* myThen = factory->newThen(&v1, &v2);
    assert(value1 * value2 == myThen->evaluate());
}

void testAggMax(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeAgg(&aggMax);
    core::Expression<num_t>* myAgg = factory->newAgg(&v1, &v2);
    assert(max(value1, value2) == myAgg->evaluate());
}

void testAggPlus(core::FuzzyFactory<num_t>* factory)
{
    num_t value1 = 0.2;
    num_t value2 = 0.9;
    core::ValueModel<num_t> v1(value1);
    core::ValueModel<num_t> v2(value2);
    factory->changeAgg(&aggPlus);
    core::Expression<num_t>* myAgg = factory->newAgg(&v1, &v2);
    assert(max(0, min(1, value1 + value2)) == myAgg->evaluate());
}

void testNotMinus1(core::FuzzyFactory<num_t>* factory)
{
    num_t value = 0.3;
    core::ValueModel<num_t> v(value);
    factory->changeNot(&notMinus1);
    core::Expression<num_t>* myNot = factory->newNot(&v);
    assert(1 - value == myNot->evaluate());
}

void testIsGaussian(core::FuzzyFactory<num_t>* factory)
{
    num_t value = 0.3;
    core::ValueModel<num_t> v(value);
    core::Expression<num_t>* myIs = factory->newIs(&isGaussian, &v);
    num_t result = myIs->evaluate();
    assert(result > 0.13 && result < 0.14);
}

void testIsSigmoid(core::FuzzyFactory<num_t>* factory)
{
    num_t value = 0.3;
    core::ValueModel<num_t> v(value);
    core::Expression<num_t>* myIs = factory->newIs(&isSigmoid, &v);
    num_t result = myIs->evaluate();
    assert(result > 0.45 && result < 0.46);
}

void testIsTriangle(core::FuzzyFactory<num_t>* factory)
{
    num_t value = 0.3;
    core::ValueModel<num_t> v(value);
    core::Expression<num_t>* myIs = factory->newIs(&isTriangle, &v);
    num_t result = myIs->evaluate();
    assert(result > 0.33 && result < 0.34);
}

void sugeno(core::FuzzyFactory<num_t>* factory)
{
    fuzzy::SugenoThen<num_t> sugenoThen;
    factory->changeThen(&sugenoThen);
    core::ValueModel<num_t> input1(3);
    core::ValueModel<num_t> input2(8);
    core::ValueModel<num_t> z1(0.2);
    core::ValueModel<num_t> z2(0.5);
    core::ValueModel<num_t> z3(0.8);
    fuzzy::IsGaussian<num_t> isGaussian1(0, 2);
    fuzzy::IsGaussian<num_t> isGaussian2(5, 2);
    fuzzy::IsGaussian<num_t> isGaussian3(10, 2);
    fuzzy::IsTrapezoidLeft<num_t> isTrapezoid1(1, 3.5);
    fuzzy::IsTrapezoidRight<num_t> isTrapezoid3(6.5, 9);
    core::Expression<num_t>* or1 = factory->newOr(factory->newIs(&isGaussian1, &input1), factory->newIs(&isTrapezoid1, &input2));
    core::Expression<num_t>* is2 = factory->newIs(&isGaussian2, &input1);
    core::Expression<num_t>* or3 = factory->newOr(factory->newIs(&isGaussian3, &input1), factory->newIs(&isTrapezoid3, &input2));
    core::Expression<num_t>* then1 = factory->newThen(or1, &z1);
    core::Expression<num_t>* then2 = factory->newThen(is2, &z2);
    core::Expression<num_t>* then3 = factory->newThen(or3, &z3);
    std::vector<core::Expression<num_t>*> vec;
    vec.push_back(then1);
    vec.push_back(then2);
    vec.push_back(then3);
    fuzzy::SugenoDefuzz<num_t> defuzz;
    num_t x = defuzz.evaluate(vec);
    std::cout << x;
}

int main(int argc, char* argv[])
{
    core::FuzzyFactory<num_t> f(&notMinus1, &andMin, &orMax, &thenMin, &aggMax, &opDefuzz);
    core::FuzzyFactory<num_t> factory(&notMinus1, &andMin, &orPlus, &thenMult, &aggPlus, &opDefuzz);

    testValueModel();

    testAndMin(&factory);
    testAndMult(&factory);

    testOrMax(&factory);
    testOrPlus(&factory);

    testThenMin(&factory);
    testThenMult(&factory);

    testAggMax(&factory);
    testAggPlus(&factory);

    testNotMinus1(&factory);

    core::ValueModel<num_t> v4(3.5);
    fuzzy::IsTrapezoid<num_t> isTrapezoid(1, 2, 3, 4);
    std::cout << isTrapezoid.evaluate(&v4) << std::endl;

    testIsGaussian(&factory);
    testIsSigmoid(&factory);
    testIsTriangle(&factory);

    sugeno(&factory);

    testCogDefuzz(&f);

    return 0;
}
