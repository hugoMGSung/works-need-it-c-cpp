#include <iostream>

int main() 
{
    bool b = true;

    std::cout.setf(std::ios::boolalpha);
    std::cout << b << std::endl; // true
    std::cout << !b << std::endl; // false

    std::cout.unsetf(std::ios::boolalpha);
    std::cout << b << std::endl; // 1
    std::cout << !b << std::endl; // 0

    return 0;
}