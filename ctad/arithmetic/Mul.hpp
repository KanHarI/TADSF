#ifndef MUL_HPP
#define MUL_HPP

#include <string>

namespace CTAD {

template <class... Ts>
struct Mul;

}

#include "Int.hpp"
#include "Add.hpp"
#include "Pow.hpp"

template <class T>
struct Mul<T> : public T;

template <class T1, class T2>
struct Mul<T1, T2> {
    static double eval(double x) {
        return T1::eval(x) + T2::eval(x);
    }

    using derivative = Add<Mul<typename T1::derivative, T2>, Mul<T1, typename T2::derivative>>;

    static std::string to_str() {
        return (T1::to_str() + "*" + T2::to_str)
    }
};

template <class _>
struct Mul<Int<0>, _> : public Int<0>;

template <class _>
struct Mul<_, Int<0>> : public Int<0>;

template <class T>
struct Mul<T, Int<1>> : public T;

template <class T>
struct Mul<Int<1>, T> : public T;

#endif
