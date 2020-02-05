//
// Created by mac air on 05/02/2020.
//

#ifndef FUZZY_ISSIGMOID_H
#define FUZZY_ISSIGMOID_H
#include <cmath>

#include "Operators.h"

namespace fuzzy {

    template<typename T>
    class IsSigmoid : public Is<T> {

    private:
        T mid;

    public:
        IsSigmoid(const T &_mid);

        IsSigmoid();


        T evaluate(core::Expression<T> *expression) const ;
    };

    template<typename T>
    IsSigmoid<T>::IsSigmoid(const T &_mid)
            : mid(_mid) {

    }

    template<typename T>
    IsSigmoid<T>::IsSigmoid()
            : IsSigmoid(0) {

    }


    template<typename T>
    T IsSigmoid<T>::evaluate(core::Expression<T> *expression) const {



        return 1 / (1 + std::exp(-expression->evaluate() - mid));
    }
}

#endif //FUZZY_ISSIGMOID_H
