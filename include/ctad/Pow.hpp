#ifndef POW_HPP
#define POW_HPP

#include <string>
#include <cmath>

namespace CTAD {

template <class... Ts>
struct Pow;

};

#include "Int.hpp"

namespace CTAD {

template <class Tbase, class Texp>
struct Pow<Tbase, Texp> {
    static double eval(double x) {
        return pow(Tbase::eval(x), Texp::eval(x));
    }

    static std::string to_str() {
        return "(" + Tbase::to_str() + "^" + Texp::to_str() + ")";
    }

    using canonize = Pow<typename Tbase::canonize, typename Texp::canonize>;
};

template <class Tbase>
struct Pow<Tbase, Int<1>> : public Tbase {};

template <class Tbase>
struct Pow<Tbase, Int<0>> : public Int<1> {};

struct _zeroToZeroErr {};
template <>
struct Pow<Int<0>, Int<0>> : public _zeroToZeroErr {};

}

#endif
