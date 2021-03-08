//
// Created by Gusts Kaksis on 3/6/21.
//

#include "MyCrossPlatformClass.hpp"

#include <iostream>

void MyCrossPlatformClass::cppMethod() const noexcept
{
    std::cout << "C++ method called\n";
}
