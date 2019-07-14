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
#include "consts.hpp"

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

struct _logZeroErr {};
template <>
struct Log<Int<0>> : public _logZeroErr {};

template <>
struct Log<Int<1>> : public Int<0> {};

template <>
struct Log<E> : public Int<1> {};

}

#endif
