#include <iostream>
#include "Complex.hpp"

int main(int argc, const char * argv[])
{
    Complex z1(3, 1);
    Complex z2(5, -2);
    std::cout << z1 * z2 << std::endl;
    std::cout << z1 / z2 << std::endl;
    std::cout << 3 * z1 + 4 * z2 << std::endl;
    std::cout << z1.abs() << std::endl;
    std::cout << z2.arg() << std::endl;
    std::cout << z1.reverse() << std::endl;
    z1.roots(5, std::cout);
    
    
    return 0;
}
