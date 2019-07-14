#ifndef CONSTS_HPP
#define CONSTS_HPP

#include <cmath>

#include "Div.hpp"
#include "Int.hpp"

#define DEF_CONST(NAME, VAL) using NAME = Div<Int<static_cast<int>(VAL*denominator+0.5)>, Int<denominator>>

namespace CTAD {

constexpr int denominator = 1000000; // Accurate to the millionth part.
// Setting this const too high can cause overflow upon lowest common
// multiplier calculations! This calculation occures implicitly when
// adding two fractions... If this happens you should get a warning
// on most modern compilers.

DEF_CONST(Pi, M_PI);
DEF_CONST(E, M_E);

}

#endif
