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

    using derivative = typename Add<Mul<typename T1::derivative, T2>, Mul<T1, typename T2::derivative>>::canonical;

    static std::string to_str() {
        return (T1::to_str() + "*" + T2::to_str());
    }

    using canonical = Mul<typename T1::canonical, typename T2::canonical>;
};

template <class T1, class T2, class T3, class... Ts>
struct Mul<T1, T2, T3, Ts...> : public Mul<T1, Mul<T2, T3, Ts...>> {};

// Bringing to canonical form

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

}

#endif
