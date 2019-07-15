#ifndef TRIG_HPP
#define TRIG_HPP

#include <cmath>
#include <string>

namespace TADSF {

template <class T>
struct Sin;

template <class T>
struct Cos;

template <class T>
struct Arcsin;

template <class T>
struct Arccos;

template <class T>
struct Sinh;

template <class T>
struct Cosh;

}

#include "Div.hpp"

namespace TADSF {

template <class T>
struct Sin {
    static double eval(double x) {
        return sin(T::eval(x));
    }

    static std::string to_str() {
        return "sin(" + T::to_str() + ")";
    }

    using canonize = Sin<typename T::canonize>;
};

template <class T>
struct Cos {
    static double eval(double x) {
        return cos(T::eval(x));
    }

    static std::string to_str() {
        return "cos(" + T::to_str() + ")";
    }

    using canonize = Cos<typename T::canonize>;
};

template <class T>
struct Arcsin {
    static double eval(double x) {
        return arcsin(T::eval(x));
    }

    static std::string to_str() {
        return "arcsin(" + T::to_str() + ")";
    }

    using canonize = Arcsin<typename T::canonize>;
};

template <class T>
struct Arccos {
    static double eval(double x) {
        return arccos(T::eval(x));
    }

    static std::string to_str() {
        return "arccos(" + T::to_str() + ")";
    }

    using canonize = Arccos<typename T::canonize>;
};

template <class T>
struct Sin<Arcsin<T>> : public T {};

template <class T>
struct Cos<Arccos<T>> : public T {};

template <class T>
struct Arcsin<Sin<T>> : public T {};

template <class T>
struct Arccos<Cos<T>> : public T {};

template <class T>
using Tan = Div<Sin<T>, Cos<T>>;

template <class T>
using Cot = Div<Cos<T>, Sin<T>>;

// Canonization

template <class T1, class T2>
struct Sin<Add<T1, T2>> : public Add<Mul<Sin<T1>, Cos<T2>>, Mul<Cos<T1>, Sin<T2>>> {};

template <class T1, class T2>
struct Cos<Add<T1, T2>> : public Add<Mul<Cos<T1>, Cos<T2>>, Mul<Int<-1>, Sin<T1>, Sin<T2>>> {};

}

#endif
