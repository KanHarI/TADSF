#ifndef D_HPP
#define D_HPP

#include "Add.hpp"
#include "Mul.hpp"
#include "Log.hpp"
#include "Canonical.hpp"

namespace TADSF {

template <class T>
struct _D;

template <int v>
struct _D<Int<v>> {
    using comp = Int<0>;
};

template <>
struct _D<X> {
    using comp = Int<1>;
};

template <class T1, class T2>
struct _D<Add<T1, T2>> {
    using comp = Add<typename _D<T1>::comp, typename _D<T2>::comp>;
};

template <class T1, class T2>
struct _D<Mul<T1, T2>> {
    using comp = Add<Mul<typename _D<T1>::comp, T2>, Mul<T1, typename _D<T2>::comp>>;
};

template <class Tbase, class Texp>
struct _D<Pow<Tbase, Texp>> {
    using comp = Mul<Pow<Tbase, Texp>, typename _D<Mul<Log<Tbase>, Texp>>::comp>;
};

template <class T>
struct _D<Log<T>> {
    using comp = Mul<typename _D<T>::comp, Pow<T, Int<-1>>>;
};

template <class T>
struct _D<Sin<T>> {
    using comp = Mul<Cos<T>, typename _D<T>::comp>;
};

template <class T>
struct _D<Cos<T>> {
    using comp = Mul<Int<-1>, Sin<T>, typename _D<T>::comp>;
};

template <class T>
struct _D<Arcsin<T>> {
    using comp =
        Div<
            typename _D<T>::comp,
            Pow<
                Add<Int<1>, Mul<Int<-1>, Pow<X, Int<2>>>>,
                Div<Int<1>, Int<2>>
            >
        >;
};

template <class T>
using D = Canonical<typename _D<Canonical<T>>::comp>;

}

#endif
