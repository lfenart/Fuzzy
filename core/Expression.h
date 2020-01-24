//
// Created by lucasf on 24/01/2020.
//

#ifndef FUZZY_EXPRESSION_H
#define FUZZY_EXPRESSION_H

template<class T>
class Expression {
public:
    virtual T evaluate() const = 0;
};

#endif //FUZZY_EXPRESSION_H