#ifndef FUZZY_NOTMINUS1_H
#define FUZZY_NOTMINUS1_H

#include "Operators.h"
namespace fuzzy {

template <class T>
class NotMinus1 : public fuzzy::Not<T> {
public:
    virtual ~NotMinus1() {};
    T evaluate(core::Expression<T>* operand) const override;
};

template <typename T>
T NotMinus1<T>::evaluate(core::Expression<T>* operand) const
{

    return 1 - operand->evaluate();
};

}

#endif //FUZZY_NOTMINUS1_H
