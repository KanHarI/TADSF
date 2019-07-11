#ifndef X_HPP
#define X_HPP

#include <string>

struct X {
    static double eval(double x) {
        return x;
    }

    static std::string to_str() {
        return "x";
    }
};

#endif
