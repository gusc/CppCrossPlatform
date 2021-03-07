//
// Created by Gusts Kaksis on 3/6/21.
//

#include <Windows.h>

MyCrossPlatformClass::MyCrossPlatformClass()
{
}

MyCrossPlatformClass::~MyCrossPlatformClass()
{
}

void MyCrossPlatformClass::platformNativeMethod() const
{
    OutputDebugStringA("Windows method called");
    OutputDebugStringA("\n");
}
