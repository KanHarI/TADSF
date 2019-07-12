#ifndef POW_HPP
#define POW_HPP

#include <string>
#include <cmath>

namespace CTAD {

template <class... Ts>
struct Pow;

};

#include "Mul.hpp"
#include "Add.hpp"
#include "Log.hpp"
#include "Canonical.hpp"

namespace CTAD {

template <class Tbase, class Texp>
struct Pow<Tbase, Texp> {
    static double eval(double x) {
        return pow(Tbase::eval(x), Texp::eval(x));
    }

    using derivative = Mul<Pow<Tbase, Texp>, typename Mul<Log<Tbase>, Texp>::derivative>;

    static std::string to_str() {
        return "(" + Tbase::to_str() + "^" + Texp::to_str() + ")";
    }

    using canonize = Pow<typename Tbase::canonize, typename Texp::canonize>;
};

}

#endif
