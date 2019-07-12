#ifndef POW_HPP
#define POW_HPP

#include <string>
#include <cmath>

namespace CTAD {

template <class Tbase, class Texp>
struct Pow;

};

#include "Mul.hpp"
#include "Add.hpp"

template <class Tbase, class Texp>
struct Pow<Tbase, Texp> {
    static double eval(double x) {
        return pow(Tbase::eval(x), Texp::eval(x));
    }

    using derivative = Mul<Pow<Tbase, Texp>, typename Mul<Log<Tbase>, Texp>::derivative>;

    static std::string to_str() {
        return "(" + Tbase::to_str() + "^" + Texp::to_str() + ")";
    }
};

#endif
