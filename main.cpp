#include "core/FuzzyFactory.h"
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
#include "fuzzy/Operators.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/ThenMult.h"
#include <cstring>
#include <iostream>
#include <vector>

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

int main(int argc, char** argv)
{
    core::FuzzyFactory<num_t> f(&notMinus1, &andMin, &orMax, &thenMin, &aggMax, &opDefuzz);
    if (strcmp(argv[1], "AggPlus") == 0) {
        f.changeAgg(&aggPlus);
    }
    if (strcmp(argv[2], "AndMult") == 0) {
        f.changeAnd(&andMult);
    }
    if (strcmp(argv[3], "OrPlus") == 0) {
        f.changeOr(&orPlus);
    }
    if (strcmp(argv[4], "ThenMult") == 0) {
        f.changeThen(&thenMult);
    }
    int i = 5;

    std::vector<fuzzy::Is<num_t>*> iss;
    while (i < argc - 5) {
        if (strcmp(argv[i], "IsGaussian") == 0) {
            iss.push_back(new fuzzy::IsGaussian<num_t>(strtod(argv[i + 1], NULL), strtod(argv[i + 2], NULL)));
            i += 3;
        } else if (strcmp(argv[i], "IsTriangle") == 0) {
            iss.push_back(new fuzzy::IsTriangle<num_t>(strtod(argv[i + 1], NULL), strtod(argv[i + 2], NULL), strtod(argv[i + 3], NULL)));
            i += 4;
        } else if (strcmp(argv[i], "IsTrapezoidLeft") == 0) {
            iss.push_back(new fuzzy::IsTrapezoidLeft<num_t>(strtod(argv[i + 1], NULL), strtod(argv[i + 2], NULL)));
            i += 3;
        } else if (strcmp(argv[i], "IsTrapezoidRight") == 0) {
            iss.push_back(new fuzzy::IsTrapezoidRight<num_t>(strtod(argv[i + 1], NULL), strtod(argv[i + 2], NULL)));
            i += 3;
        } else if (strcmp(argv[i], "IsTrapezoid") == 0) {
            iss.push_back(new fuzzy::IsTrapezoid<num_t>(strtod(argv[i + 1], NULL), strtod(argv[i + 2], NULL), strtod(argv[i + 3], NULL), strtod(argv[i + 4], NULL)));
            i += 5;
        } else if (strcmp(argv[i], "IsSigmoid") == 0) {
            iss.push_back(new fuzzy::IsSigmoid<num_t>(strtod(argv[i + 1], NULL)));
            i += 2;
        } else if (strcmp(argv[i], "None") == 0) {
            iss.push_back(NULL);
            i += 1;
        } else {
            std::cout << "Error" << std::endl;
            return 1;
        }
    }
    core::ValueModel<num_t> service(strtod(argv[i], NULL));
    core::ValueModel<num_t> food(strtod(argv[i + 1], NULL));
    core::ValueModel<num_t> tip(0);
    core::Expression<num_t>* left1;
    core::Expression<num_t>* left2;
    core::Expression<num_t>* left3;
    if (iss[0] != NULL && iss[3] != NULL) {
        if (strcmp(argv[i + 2], "Or") == 0) {
            left1 = f.newOr(f.newIs(iss[0], &service), f.newIs(iss[3], &food));
        } else {
            left1 = f.newAnd(f.newIs(iss[0], &service), f.newIs(iss[3], &food));
        }
    } else {
        if (iss[0] != NULL) {
            left1 = f.newIs(iss[0], &service);
        } else {
            left1 = f.newIs(iss[3], &food);
        }
    }
    if (iss[1] != NULL && iss[4] != NULL) {
        if (strcmp(argv[i + 3], "Or") == 0) {
            left2 = f.newOr(f.newIs(iss[1], &service), f.newIs(iss[4], &food));
        } else {
            left2 = f.newAnd(f.newIs(iss[1], &service), f.newIs(iss[4], &food));
        }
    } else {
        if (iss[1] != NULL) {
            left2 = f.newIs(iss[1], &service);
        } else {
            left2 = f.newIs(iss[4], &food);
        }
    }
    if (iss[2] != NULL && iss[5] != NULL) {
        if (strcmp(argv[i + 4], "Or") == 0) {
            left3 = f.newOr(f.newIs(iss[2], &service), f.newIs(iss[5], &food));
        } else {
            left3 = f.newAnd(f.newIs(iss[2], &service), f.newIs(iss[5], &food));
        }
    } else {
        if (iss[2] != NULL) {
            left2 = f.newIs(iss[2], &service);
        } else {
            left2 = f.newIs(iss[5], &food);
        }
    }
    core::Expression<num_t>* r = f.newAgg(
        f.newAgg(
            f.newThen(
                left1,
                f.newIs(iss[6], &tip)),
            f.newThen(
                left2,
                f.newIs(iss[7], &tip))),
        f.newThen(
            left3,
            f.newIs(iss[8], &tip)));
    core::Expression<num_t>* system = f.newDefuzz(&tip, r, 0, 25, 1);
    std::cout << "tips->" << system->evaluate() << std::endl;
    return 0;
}