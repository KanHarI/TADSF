# CTAD

A compile time autodifferentiation library.
The library works by pattern matching symbolic mathematical expressions, and by rule-based substitution.

#Usage
Include the `ctad.h` header, and use namespace `CTAD`.
Look at the `examples` folder contents for a compiling example.
The following should be self explanatory:
```
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
```

Leads to:
```
my_simple_func:
((x*(x^2))+(-2+(2+x)))
my_canonized_simple_func:
((x^3)+x)
my_simple_func value at 5
130
Derivative: 
(1+(3*(x^2)))
Derivative at 5: 76


my_func: (((x^x)*((x^3)*((5/1)*(x^-1))))+((x^3)+sin(x)))
my_canonized_function: 
((5*(x^(2+x)))+((x^3)+sin(x)))
My func at 3: 
1242.14
Derivative: 
((5*((x^(2+x))*(((x^-1)*(2+x))+log(x))))+((3*(x^2))+cos(x)))
Derivative at 3: 3385.82
```

I manually checked this derivative and it is correct :)

This library probably has some bugs in it, please contant me at `knaan.harpaz@gmail.com` to report them!
