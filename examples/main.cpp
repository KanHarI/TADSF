
#include <iostream>
#include <typeinfo>

#include "tadsf.h"

using namespace TADSF;

int main() {
    using my_simple_func = Add<Mul<X, X, X>, Add<X, Int<2>>, Int<-2>>;
    std::cout << "my_simple_func:" << std::endl << my_simple_func::to_str() << std::endl;
    using my_canonized_simple_func = Canonical<my_simple_func>;
    std::cout << "my_canonized_simple_func:" << std::endl << my_canonized_simple_func::to_str() << std::endl;
    std::cout << "my_simple_func value at 5" << std::endl << my_simple_func::eval(5) << std::endl;
    
    using my_simple_func_der = D<my_simple_func>;
    std::cout << "Derivative: " << std::endl << my_simple_func_der::to_str() << std::endl;
    std::cout << "Derivative at 5: " << my_simple_func_der::eval(5) << std::endl;

    std::cout << std::endl << std::endl;

    using my_func = Add<Mul<Pow<X, X>, Pow<X,Int<3>>, Div<Int<10>, Mul<Int<2>, X>>>, Pow<X, Int<3>>, Sin<X>>;
    std::cout << "my_func: " << my_func::to_str() << std::endl;
    using my_canonized_func = Canonical<my_func>;
    std::cout << "my_canonized_function: " << std::endl << my_canonized_func::to_str() << std::endl;
    std::cout << "My func at 3: " << std::endl << my_func::eval(3) << std::endl;
    
    using my_func_der = D<my_func>;
    std::cout << "Derivative: " << std::endl << my_func_der::to_str() << std::endl;
    std::cout << "Derivative at 3: " << my_func_der::eval(3) << std::endl;

    return 0;
}
