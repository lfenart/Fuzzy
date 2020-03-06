//
// Created by Lucas Schloesslin on 06/03/2020.
//

#ifndef FUZZY_SUGENOCONCLUSION_H
#define FUZZY_SUGENOCONCLUSION_H


#include "../core/NaryExpression.h"

namespace fuzzy {
    template <typename T>
    class SugenoConclusion : public core::NaryExpression<T> {
    private:
        std::vector<T> coeff;
    public:
        SugenoConclusion(std::vector<T>);
        T evaluate(std::vector<core::Expression<T>*>) const;
    };

    template <class T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T> _coeff){
        coeff = _coeff;
    }

    template <typename T>
    T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*> operands) const
    {
        T retValue = 0;
        for (int i = 0; i < operands.size(); i++){
            retValue += coeff[i]*(operands[i]->evaluate());
        }
        retValue += coeff[operands.size()];
        return retValue;
    }

}

#endif //FUZZY_SUGENOCONCLUSION_H
