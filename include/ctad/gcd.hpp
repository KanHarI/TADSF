#ifndef GCD_HPP
#define GCD_HPP

#include <utility>

namespace CTAD {

constexpr int gcd(int a, int b) {
    if (a > b) {
        std::swap(a, b);
    }
    while (b%a) {
        b %= a;
        std::swap(a, b);
    }
    return a;
}

}

#endif
