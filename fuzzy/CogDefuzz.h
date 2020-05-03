//
// Created by Khadija Bahrallil on 28/02/2020.
//

#include "MamdaniDefuzz.h"

#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

#define MIN 0
#define MAX 10
#define STEP 1


namespace fuzzy {

    template<typename T>
    class CogDefuzz : public MamdaniDefuzz<T> {

    public:
        CogDefuzz(const T &_min, const T &_max, const T &_step);

        CogDefuzz();

        T defuzz(const Shape<T> &shape)  ;
    };

    template<typename T>
    CogDefuzz<T>::CogDefuzz(const T &_min, const T &_max, const T &_step)
            : MamdaniDefuzz<T>(_min, _max, _step) {
    }

    template<typename T>
    CogDefuzz<T>::CogDefuzz() : CogDefuzz(MIN, MAX, STEP) {

    }

    template<typename T>
    T CogDefuzz<T>::defuzz(const Shape<T> &shape) {
        T numerateur(0);
        T denominateur(0);

        for (auto point : shape) {

            const T &x = point.first;
            const T &y = point.second;

            numerateur += x * y;
            denominateur += y;
        }

        return (denominateur != 0) ? numerateur / denominateur : 0;

    }


}

#endif //FUZZY_COGDEFUZZ_H
