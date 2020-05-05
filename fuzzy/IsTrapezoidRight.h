
#ifndef FUZZY_ISTRAPEZOIDRIGHT_H
#define FUZZY_ISTRAPEZOIDRIGHT_H

#include "Operators.h"

namespace fuzzy {
    template<typename T>
    class IsTrapezoidRight : public Is<T> {
    public:
        IsTrapezoidRight(const T &, const T &);

        virtual ~IsTrapezoidRight() {};

        T evaluate(core::Expression<T> *) const;

        const T &getMin() const;

        const T &getMax() const;

        void setMin(const T &);

        void setMax(const T &);

    private:
        T min;
        T max;
    };

    template<typename T>
    IsTrapezoidRight<T>::IsTrapezoidRight(const T &_min, const T &_max): min(_min), max(_max) {
    }

    template<typename T>
    T IsTrapezoidRight<T>::evaluate(core::Expression<T> *expression) const {
        T value = expression->evaluate();
        if (value <= min) {
            return 0;
        } else if (value >= min && value <= max) {
            return (value - min) / (max - min);
        } else if (value >= max) {
            return 1;
        }
        return 0;
    }

    template<typename T>
    const T &IsTrapezoidRight<T>::getMin() const {
        return min;
    }

    template<typename T>
    const T &IsTrapezoidRight<T>::getMax() const {
        return max;
    }

    template<typename T>
    void IsTrapezoidRight<T>::setMin(const T &_min) {
        min = _min;
    }

    template<typename T>
    void IsTrapezoidRight<T>::setMax(const T &_max) {
        max = _max;
    }

}

#endif //FUZZY_ISTRAPEZOIDRIGHT_H
