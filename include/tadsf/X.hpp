#ifndef X_HPP
#define X_HPP

#include <string>

namespace TADSF {

struct X;

}

#include "Int.hpp"

namespace TADSF {

struct X {
    static double eval(double x) {
        return x;
    }

    using derivative = Int<1>;

    static std::string to_str() {
        return "x";
    }

    using canonize = X;
};

}

#endif
