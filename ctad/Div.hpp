#ifndef DIV_HPP
#define DIV_HPP

namespace CTAD {

template <class... Ts>
struct Div;

}

#include "Int.hpp"
#include "Add.hpp"
#include "Mul.hpp"
#include "Pow.hpp"
#include "Canonical.hpp"

namespace CTAD {

template <class T1, class T2>
struct Div<T1, T2> {
    static double eval(double x) {
        return T1::eval(x)/T2::eval(x);
    }

    using derivative = 
        Div<
            Add<
                Mul<typename T1::derivative, T2>,
                Mul<Int<-1>, T1, typename T2::derivative>
            >,
            Pow<T2, Int<2>>
        >;

    static std::string to_str() {
        return "(" + T1::to_str() + "/" + T2::to_str() + ")";
    }

    using canonize = Div<typename T1::canonize, typename T2::canonize>;
};

template <class _>
struct Div<_, Int<0>> : public _::divisionByZeroErr {};

template <class _>
struct Div<Int<0>, _> : public Int<0> {};

template <class T>
struct Div<T, T> : public Int<1> {};

template <class T, class... Ts1, class... Ts2>
struct Div<
    Mul<T, Ts1...>,
    Mul<T, Ts2...>
> : public Div<Mul<Ts1...>, Mul<Ts2...>> {};

}

#endif
