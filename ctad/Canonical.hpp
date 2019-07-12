#ifndef CANONICAL_HPP
#define CANONICAL_HPP

namespace CTAD {

template <class T1, class T2>
constexpr bool is_same_type = false;

template <class T>
constexpr bool is_same_type<T, T> = true;

template <class T, bool is_same>
struct _Canonical {
    using comp = T;
};

template <class T>
struct _Canonical<T, false> {
    using comp = typename _Canonical<typename T::canonize, is_same_type<T, typename T::canonize>>::comp;
};

template <class T>
using Canonical = typename _Canonical<T, false>::comp;
// Canonizes the expression until a fixed point is reached

}

#endif
