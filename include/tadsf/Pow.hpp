#ifndef POW_HPP
#define POW_HPP

#include <string>
#include <cmath>

namespace TADSF {

template <class... Ts>
struct Pow;

};

#include "Int.hpp"
#include "utils.hpp"
#include "consts.hpp"

namespace TADSF {

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

template <class Texp>
struct Pow<Int<1>, Texp> : public Int<1> {};

template <class Texp>
struct Pow<Int<0>, Texp> : public Int<0> {};

template <>
struct Pow<Int<1>, Int<1>> : public Int<1> {};

template <>
struct Pow<Int<1>, Int<0>> : public Int<1> {};

template <int v>
struct Pow<Int<1>, Int<v>> : public Int<1> {};

template <int v>
struct Pow<Int<0>, Int<v>> : public Int<0> {};

struct _zeroToZeroErr {};
template <>
struct Pow<Int<0>, Int<0>> : public _zeroToZeroErr {};

template <int vbase, int vexp>
struct Pow<Int<vbase>, Int<vexp>> {
    static constexpr int _vbase = vexp > 0 ? ctpow(vbase, vexp) : ctpow(vbase, -vexp);
    static constexpr int _vexp = vexp > 0 ? 1 : -1;
    
    static double eval(double x) {
        if (_vexp == 1) {
            return static_cast<double>(_vbase);
        }
        return 1.0/static_cast<double>(_vbase);
    }

    static std::string to_str() {
        return "(" + Int<vbase>::to_str() + "^" + Int<vexp>::to_str() + ")";
    }

    using canonize = Pow<Int<_vbase>, Int<_vexp>>;
};

}

#endif
