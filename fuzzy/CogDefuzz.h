
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
        CogDefuzz(){};
        ~CogDefuzz(){};
        virtual T defuzz(typename MamdaniDefuzz<T>::Shape) const;
    };

    template<typename T>
    T CogDefuzz<T>::defuzz(typename MamdaniDefuzz<T>::Shape shape) const {
        T den = 0;
        T num = 0;
        for(unsigned int i = 0; i<shape.first.size();i++){
            num = num + shape.first.at(i) * shape.second.at(i);
            den = den + shape.second.at(i);
        }
        if(den == 0) return 0;
        return num/den;

    }


}

#endif //FUZZY_COGDEFUZZ_H
