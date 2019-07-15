#ifndef ADD_HPP
#define ADD_HPP

#include <string>

namespace TADSF {

template <class... Ts>
struct Add;

}

#include "Int.hpp"
#include "Mul.hpp"
#include "Trig.hpp"
#include "X.hpp"

namespace TADSF {

template <>
struct Add<> : public Int<0> {};

template <class T>
struct Add<T> : public T {};

template <class T1, class T2>
struct Add<T1, T2> {
    static double eval(double x) {
        return T1::eval(x) + T2::eval(x);
    }

    static std::string to_str() {
        return "(" + T1::to_str() + "+" + T2::to_str() + ")";
    }

    using canonize = Add<typename T1::canonize, typename T2::canonize>;
};


template <class T1, class T2, class T3, class... Ts>
struct Add<T1, T2, T3, Ts...> : public Add<T1, Add<T2, T3, Ts...>> {};


// Bringing to canonical form


template <class T>
struct Add<T, T> : public Mul<Int<2>, T> {};

template <int v, class T>
struct Add<T, Int<v>> : public Add<Int<v>, T> {};

template <int v1, int v2>
struct Add<Int<v1>, Int<v2>> : public Int<v1+v2> {};

template <int v1, int v2, class T>
struct Add<Int<v1>, Add<Int<v2>, T>> : public Add<Int<v1+v2>, T> {};

template <int v>
struct Add<Int<v>, Int<v>> : public Int<2*v> {};

template <class T>
struct Add<Int<0>, T> : public T {};

template <int v>
struct Add<Int<0>, Int<v>> : public Int<v> {};

template <int v>
struct Add<Int<v>, Int<0>> : public Int<v> {};

template <class T>
struct Add<T, Int<0>> : public T {};

template <>
struct Add<Int<0>, Int<0>> : public Int<0> {};

template <class T>
struct Add<T, Mul<Int<-1>, T>> : public Int<0> {};

template <class T>
struct Add<Mul<Int<-1>, T>, T> : public Int<0> {};

template <class T, class T2>
struct Add<Mul<T2, T>, T> : public Mul<Add<T2, Int<1>>, T> {};

template <class T, class T2>
struct Add<Mul<T, T2>, T> : public Mul<T, Add<T2, Int<1>>> {};

template <class T, class T2>
struct Add<T, Mul<T, T2>> : public Mul<T, Add<T2, Int<1>>> {};

template <class T, class T2>
struct Add<T, Mul<T2, T>> : public Mul<Add<T2, Int<1>>, T> {};

template <class T>
struct Add<T, Mul<T, T>> : public Mul<T, Add<T, Int<1>>> {};

template <class T>
struct Add<Mul<T, T>, T> : public Mul<Add<T, Int<1>>, T> {};

template <class T, class T2, class T3>
struct Add<Mul<T2, T>, Mul<T3, T>> : public Mul<Add<T2, T3>, T> {};

template <class T, class T2, class T3>
struct Add<Mul<T, T2>, Mul<T3, T>> : public Mul<Add<T2, T3>, T> {};

template <class T, class T2, class T3>
struct Add<Mul<T2, T>, Mul<T, T3>> : public Mul<Add<T2, T3>, T> {};

template <class T, class T2, class T3>
struct Add<Mul<T, T2>, Mul<T, T3>> : public Mul<T, Add<T2, T3>> {};

template <class T>
struct Add<Pow<Sin<T>, Int<2>>, Pow<Cos<T>, Int<2>>> : public Int<1> {};

template <class T1, class T2, int d1, int d2>
struct Add<Div<T1, Int<d1>>, Div<T2, Int<d2>>> : public Div<Add<Mul<Int<d2>, T1>, Mul<Int<d1>, T2>>, Mul<Int<d1*d2>>> {};

}

#endif
