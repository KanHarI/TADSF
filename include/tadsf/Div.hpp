#ifndef DIV_HPP
#define DIV_HPP

#include <type_traits>

namespace TADSF {

template <class... Ts>
struct Div;

}

#include "Int.hpp"
#include "Add.hpp"
#include "Mul.hpp"
#include "Pow.hpp"

namespace TADSF {

template <class T1, class T2>
struct Div<T1, T2> : public Mul<T1, Pow<T2, Int<-1>>> {};

template <class _>
struct Div<_, Int<0>> : public _::divisionByZeroErr {};

template <class _>
struct Div<Int<0>, _> : public Int<0> {};

template <class T>
struct Div<T, T> : public Int<1> {};

}

#endif
