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
#include "Log.hpp"

namespace CTAD {

template <class Tbase, class Texp>
struct Pow {
    static double eval(double x) {
        return pow(Tbase::eval(x), Texp::eval(x));
    }

    using derivative = typename Mul<Pow<Tbase, Texp>, typename Mul<Log<Tbase>, Texp>::derivative>::canonical;

    static std::string to_str() {
        return "(" + Tbase::to_str() + "^" + Texp::to_str() + ")";
    }

    using canonical = Pow<typename Tbase::canonical, typename Texp::canonical>;
};

}

#endif
