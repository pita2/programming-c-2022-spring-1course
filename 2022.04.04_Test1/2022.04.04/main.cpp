#include <iostream>
#include "Fraction.hpp"

int main(int argc, const char * argv[])
{
    Fraction fr1(3, 1);
    Fraction fr2(5, -2);
    std::cout << fr1 * fr2 << std::endl;
    std::cout << fr1 / fr2 << std::endl;
    std::cout << 1 / (3 * fr1 + 4 * fr2) << std::endl;
    std::cout << fr1.abs() << std::endl;
    std::cout << fr1.reverse() << std::endl;
    std::cout << fr2.deg(2) << std::endl;
    std::cout << fr2 << std::endl;
    return 0;
}
