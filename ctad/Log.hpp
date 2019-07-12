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
struct Log {
    static double eval(double x) {
        return log(x);
    }

    using derivative = typename Div<typename T::derivative, T>::canonical;

    static std::string to_str() {
        return "log(" + T::to_str() + ")";
    }

    using canonical = Log<typename T::canonical>;
};

}

#endif
