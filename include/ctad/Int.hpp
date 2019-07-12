#ifndef INT_HPP
#define INT_HPP

#include <string>

namespace CTAD {

template <int value>
struct Int {
    static constexpr int val = value;
    static double eval(double x) {
        return value;
    }
    
    using derivative = Int<0>;

    static std::string to_str() {
        return std::to_string(value);
    }

    using canonize = Int<value>;
};

}

#endif
