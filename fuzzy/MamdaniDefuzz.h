//
// Created by Khadija Bahrallil on 26/02/2020.
//

#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include <iostream>
#include "../core/ValueModel.h"
#include "../core/BinaryExpression.h"

namespace fuzzy {

    template <typename T>
class MamdaniDefuzz : public core::BinaryExpression<T>{
    public:
        MamdaniDefuzz(const T &, const T &, const T &);
        ~MamdaniDefuzz(){};

        typedef std::pair<std::vector<T>, std::vector<T>> Shape;
        virtual T evaluate(core::Expression<T> *left, core::Expression<T> *right) const ;
        virtual Shape buildShape(core::Expression<T>*, core::Expression<T>*) const;
        virtual T defuzz(const typename MamdaniDefuzz<T>::Shape&) const = 0 ;

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
        return defuzz(buildShape(left, right));
    }

    template<typename T>
    typename MamdaniDefuzz<T>::Shape MamdaniDefuzz<T>::buildShape(core::Expression<T>* in, core::Expression<T>* out) const {
        std::vector<T> x, y;
        for (T i= min; i <= max; i += step) {
            in->setValue(&i);
            y.push_back(out->evaluate());
            x.push_back(i);
        }
        return Shape(x,y);
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
