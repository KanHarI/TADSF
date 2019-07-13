
#include <iostream>
#include <typeinfo>

#include <cxxabi.h>

#include "ctad.h"

using namespace CTAD;

int main() {
    using my_func = Canonical<Add<Pow<X, X>, Pow<X,Int<3>>, Div<Int<10>, Mul<Int<2>, X>>>>;
    int status;
    
    std::cout << "My func: " << my_func::to_str() << std::endl;
    std::cout << "My func typeid: " << abi::__cxa_demangle(typeid(my_func).name(), 0, 0, &status) << std::endl;
    std::cout << "My func at 3: " << my_func::eval(3) << std::endl;
    using der = D<my_func>;
    std::cout << "Derivative: " << der::to_str() << std::endl;
    std::cout << "der typeid: " << abi::__cxa_demangle(typeid(der).name(), 0, 0, &status) << std::endl;
    std::cout << "Derivative at 3: " << der::eval(3) << std::endl;

    return 0;
}
