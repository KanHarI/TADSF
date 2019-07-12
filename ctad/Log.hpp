#ifndef LOG_HPP
#define LOG_HPP

#include <cmath>
#include <string>

namespace CTAD {

template <class T>
struct Log;
}

#include "Div.hpp"

namespace CTAD {

template <class T>
struct Log<T> {
    static double eval(double x) {
        return log(x);
    }

    using derivative = Div<typename T::derivative, T>;

    static std::string to_str() {
        return "log(" + T::to_str() + ")";
    }
};

}

#endif
