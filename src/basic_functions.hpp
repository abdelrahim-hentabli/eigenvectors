#ifndef BASIC_FUNCTIONS_HPP
#define BASIC_FUNCTIONS_HPP

#include "constants.hpp"
#include <math.h>

template <class T>
bool equality(T lhs, T rhs){
    return std::abs(lhs - rhs) <= EPS;
}

#endif //BASIC_FUNCTIONS_HPP