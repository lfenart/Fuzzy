//
// Created by xavie on 28/01/2020.
//

#ifndef FUZZY_THENMULT_H
#define FUZZY_THENMULT_H
#include "Operators.h"

namespace fuzzy{

    template<class T>
    class ThenMult : public fuzzy::Then<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
    };

    template <class T>
    T ThenMult<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
        T l=left->evaluate();
        T r=right->evaluate();

        return l*r;
    }

}
#endif //FUZZY_THENMULT_H
