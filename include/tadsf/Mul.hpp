#ifndef MUL_HPP
#define MUL_HPP

#include <string>
#include <type_traits>

namespace TADSF {

template <class... Ts>
struct Mul;

}

#include "Int.hpp"
#include "Add.hpp"
#include "Pow.hpp"
#include "utils.hpp"

namespace TADSF {

template <class T>
struct Mul<T> : public T {};

template <class T1, class T2>
struct Mul<T1, T2> {
    static double eval(double x) {
        return T1::eval(x) * T2::eval(x);
    }

    static std::string to_str() {
        return "(" + T1::to_str() + "*" + T2::to_str() + ")";
    }

    using canonize = Mul<typename T1::canonize, typename T2::canonize>;
};

template <class T1, class T2, class T3, class... Ts>
struct Mul<T1, T2, T3, Ts...> : public Mul<T1, Mul<T2, T3, Ts...>> {};

template <class _>
struct Mul<Int<0>, _> : public Int<0> {};

template <class _>
struct Mul<_, Int<0>> : public Int<0> {};

template <class T>
struct Mul<T, Int<1>> : public T {};

template <class T>
struct Mul<Int<1>, T> : public T {};

// Bringing to canonical form

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

template <class T, int v>
struct Mul<T, Int<v>> : public Mul<Int<v>, T> {};

template <class T1, class T2, int v>
struct Mul<T1, Mul<Int<v>, T2>> : public Mul<Int<v>, Mul<T1, T2>> {};

template <class T, int v1, int v2>
struct Mul<Int<v1>, Mul<Int<v2>, T>> : public Mul<Int<v1*v2>, T> {};

template <class T2, int v>
struct Mul<Int<0>, Mul<Int<v>, T2>> : public Int<0> {};

template <class T1, class T2>
struct Mul<T1, Mul<Int<1>, T2>> : public Mul<T1, T2> {};

template <int v, class T>
struct Mul<Int<v>, Mul<Int<1>, T>> : public Mul<Int<v>, T> {};

template <class T, class Texp>
struct Mul<T, Pow<T, Texp>> : public Pow<T, Add<Int<1>, Texp>> {};

template <class T, class Texp>
struct Mul<Pow<T, Texp>, T> : public Pow<T, Add<Texp, Int<1>>> {};

template <class T, class Texp1, class Texp2>
struct Mul<Pow<T, Texp1>, Pow<T, Texp2>> : public Pow<T, Add<Texp1, Texp2>> {};

template <class T, class Texp>
struct Mul<Pow<T, Texp>, Pow<T, Texp>> : public Pow<T, Add<Texp, Texp>> {};

template <int v1, int v2>
struct Mul<Int<v1>, Pow<Int<v2>, Int<-1>>> {
    static constexpr int _v1 = v1/gcd(v1, v2);
    static constexpr int _v2 = v2/gcd(v1, v2);

    static double eval(double x) {
        return static_cast<double>(_v1)/static_cast<double>(_v2);
    }

    static std::string to_str() {
        return "(" + std::to_string(_v1) + "/" + std::to_string(_v2) + ")";
    }

    using canonize =
        typename std::conditional<
            _v2==1,
            Int<_v1>,
            Mul<Int<_v1>, typename Pow<Int<_v2>, Int<-1>>::canonize>
        >::type;
};

template <int v2>
struct Mul<Int<0>, Pow<Int<v2>, Int<-1>>> : public Int<0> {};

template <int v1, int v2, class T2, int vexp2>
struct Mul<Int<v1>, Pow<Mul<Int<v2>, T2>, Int<vexp2>>> :
    public Mul<
        Mul<
            Int<v1>,
            Pow<Int<v2>, Int<vexp2>>
        >,
        Pow<T2, Int<vexp2>>
    > {};

}

#endif
