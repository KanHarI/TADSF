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

namespace CTAD {

template <class T>
struct Mul<T> : public T {};

template <class T1, class T2>
struct Mul<T1, T2> {
    static double eval(double x) {
        return T1::eval(x) * T2::eval(x);
    }

    static std::string to_str() {
        return (T1::to_str() + "*" + T2::to_str());
    }

    using canonize = Mul<typename T1::canonize, typename T2::canonize>;
};

template <class T1, class T2, class T3, class... Ts>
struct Mul<T1, T2, T3, Ts...> : public Mul<T1, Mul<T2, T3, Ts...>> {};

// Bringing to canonize form

template <class _>
struct Mul<Int<0>, _> : public Int<0> {};

template <class _>
struct Mul<_, Int<0>> : public Int<0> {};

template <class T>
struct Mul<T, Int<1>> : public T {};

template <class T>
struct Mul<Int<1>, T> : public T {};

template <class T>
struct Mul<T, T> : public Pow<T, Int<2>> {};

template <int v1, int v2>
struct Mul<Int<v1>, Int<v2>> : public Int<v1*v2> {};

template <int v>
struct Mul<Int<v>, Int<v>> : public Int<v*v> {};

template <>
struct Mul<Int<0>, Int<0>> : public Int<0> {};

template <>
struct Mul<Int<0>, Int<1>> : public Int<0> {};

template <>
struct Mul<Int<1>, Int<0>> : public Int<0> {};

template <>
struct Mul<Int<1>, Int<1>> : public Int<1> {};

template <int v>
struct Mul<Int<0>, Int<v>> : public Int<0> {};

template <int v>
struct Mul<Int<v>, Int<0>> : public Int<0> {};

template <int v>
struct Mul<Int<1>, Int<v>> : public Int<v> {};

template <int v>
struct Mul<Int<v>, Int<1>> : public Int<v> {};

template <class T, class Texp>
struct Mul<T, Pow<T, Texp>> : public Pow<T, Add<Int<1>, Texp>> {};

template <class T, class Texp>
struct Mul<Pow<T, Texp>, T> : public Pow<T, Add<Texp, Int<1>>> {};

}

#endif
