#include <iostream>

#include "core/ValueModel.h"

int main() {
    core::ValueModel<int> v;
    v.setValue(1);
    std::cout << v.evaluate() << std::endl;
    return 0;
}
