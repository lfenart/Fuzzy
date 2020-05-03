//
// Created by Khadija Bahrallil on 26/02/2020.
//

#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include <iostream>

#include "../core/Expression.h"
#include "../core/ValueModel.h"
#include "Shape.h"

namespace fuzzy {

    template <typename T>
    class MamdaniDefuzz {
    public:
        MamdaniDefuzz(const T &, const T &, const T &);

        T evaluate(core::Expression<T> *left, core::Expression<T> *right) const ;

        T defuzz(const Shape <T> &shape) const = 0 ;

        T &getMin() const;
        T &getMax() const;

        T &getStep() const;

        void setMin(const T &_min);

        void setMax(const T &_max);

        void setStep(const T &_step);
    private:
        T min;
        T max;
        T step;


    };
    template<typename T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T &_min, const T &_max, const T &_step)
            : min(_min), max(_max), step(_step) {
    }

    template<typename T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T> *left,core::Expression<T> *right) const {

        auto valueModel = dynamic_cast<core::ValueModel<T> *>(left);
        Shape<T> shape;
        if (valueModel == nullptr) {
            std::cout << "nullptr mamdani" << std::endl;
        } else {

            T stateSave = valueModel->evaluate();



            for (T x = min; x < max; x += step) {

                valueModel->setValue(x);

                T y = right->evaluate();

                shape.addPoint(x, y);
            }

            valueModel->setValue(stateSave);

        }

        return defuzz(shape);
    }

    template<typename T>
    T &MamdaniDefuzz<T>::getMin() const {
        return min;
    }

    template<typename T>
    T &MamdaniDefuzz<T>::getMax() const {
        return max;
    }

    template<typename T>
    T &MamdaniDefuzz<T>::getStep() const {
        return step;
    }

    template<typename T>
    void MamdaniDefuzz<T>::setMin(const T &_min) {
        min = _min;
    }

    template<typename T>
    void MamdaniDefuzz<T>::setMax(const T &_max) {
        max = _max;
    }

    template<typename T>
    void MamdaniDefuzz<T>::setStep(const T &_step) {
        step = _step;
    }



}

#endif //FUZZY_MAMDANIDEFUZZ_H
