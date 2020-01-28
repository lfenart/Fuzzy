//
// Created by Lucas Schloesslin on 28/01/2020.
//

#ifndef FUZZY_NOTMINUS1_H
#define FUZZY_NOTMINUS1_H

#include "Operators.h"
namespace fuzzy {

    template<class T>
    class NotMinus1 : public fuzzy::Not<T> {

    };

}

#endif //FUZZY_NOTMINUS1_H
