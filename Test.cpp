//
// Created by Gusts Kaksis on 3/6/21.
//

#include "Test.hpp"
#include "MyCrossPlatformClass.hpp"

void Test::run()
{
    MyCrossPlatformClass cls;
    cls.platformNativeMethod();
    cls.cppMethod();
}
