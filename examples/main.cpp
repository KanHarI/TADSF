
#include <iostream>
#include <typeinfo>

#include <cxxabi.h>

#include "ctad.h"

using namespace CTAD;

int main() {
    using my_func = typename Mul<X, X>::canonical;
    int status;
    std::cout << "My func: " << my_func::to_str() << std::endl;
    std::cout << "My func typeid: " << abi::__cxa_demangle(typeid(my_func).name(), 0, 0, &status) << std::endl;
    std::cout << "My func at 3: " << my_func::eval(3) << std::endl;
    /*std::cout << "Derivative: " << my_func::derivative::to_str() << std::endl;
    std::cout << "Derivative at 3: " << my_func::derivative::eval(3) << std::endl;*/
    return 0;
}
