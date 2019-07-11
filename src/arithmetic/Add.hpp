#ifndef ADD_HPP
#define ADD_HPP

#include <string>

namespace CTAD {

template <class... Ts>
struct Add;

}

#include "Int.hpp"
#include "Mul.hpp"
#include "../X.hpp"

namespace CTAD {

template <>
struct Add<> : public Int<0>;

template <class T>
struct Add<T> : public T;

template <class T1, class T2>
struct Add<T1, T2> {
    static double eval(double x) {
        return T1::eval(x) + T2::eval(x);
    }

    using derivative = Add<typename T::derivative, typename T2::derivative>;

    static std::string to_str() {
        return T::to_str() + "+" + T2::to_str();
    }
};

template <class T1, class T2, class T3, class... Ts>
struct Add<T1, T2, T3, Ts...> : public Add<T1, Add<T2, T3, Ts...>>;

template <class T>
struct Add<T, Mul<Int<-1>, T>> : public Int<0>;

template <int v>
struct Add<Int<v>, X, Ts...> : public Add<>;

}

#endif
