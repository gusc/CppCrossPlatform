//
// Created by Gusts Kaksis on 3/6/21.
//

#import "../MyCrossPlatformClass.hpp"
#import "MyCrossPlatformDelegate.hpp"

MyCrossPlatformClass::MyCrossPlatformClass()
{
    // Intialize new Objective-C companion class with this pointer
    objCObject = [[MyCrossPlatformDelegate alloc] initWithCppObject:this];
}

MyCrossPlatformClass::~MyCrossPlatformClass()
{
    // Nothing to do - once the C++ object get's destroyed the refernce to
    // objCObject get's released automatically
}

void MyCrossPlatformClass::platformNativeMethod() const
{
    // Simply call Objective-C message
    [objCObject platformNativeMethod];
}
