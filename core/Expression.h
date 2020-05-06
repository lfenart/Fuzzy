#ifndef FUZZY_EXPRESSION_H
#define FUZZY_EXPRESSION_H

namespace core {

template <class T>
class Expression {
public:
    virtual ~Expression() {};

    virtual T evaluate() const = 0;
};

}

#endif //FUZZY_EXPRESSION_H
