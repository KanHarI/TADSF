#ifndef GCD_HPP
#define GCD_HPP

namespace CTAD {

constexpr int gcd(int a, int b) {
    if (a > b) {
        a ^= b ^= a ^= b; // constexpr alternative to std::swap(a, b)
    }
    while (b%a) {
        b %= a;
        a ^= b ^= a ^= b;
    }
    return a;
}

constexpr int ctpow(int base, int exp) {
    int acc = 1;
    while(exp) {
        if (exp%2) {
            acc *= base;
        }
        exp >> 1;
        base << 1;
    }
    return acc;
}

}

#endif
