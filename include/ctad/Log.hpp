#ifndef LOG_HPP
#define LOG_HPP

#include <cmath>
#include <string>

namespace CTAD {

template <class... Ts>
struct Log;
}

#include "Mul.hpp"
#include "Pow.hpp"

namespace CTAD {

template <class T>
struct Log<T> {
    static double eval(double x) {
        return log(x);
    }

    static std::string to_str() {
        return "log(" + T::to_str() + ")";
    }

    using canonize = Log<typename T::canonize>;
};

}

#endif
