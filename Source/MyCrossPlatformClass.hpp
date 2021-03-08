//
// Created by Gusts Kaksis on 3/6/21.
//

#ifndef CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS_HPP
#define CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS_HPP

#if defined(__ANDROID__)
#   include <jni.h>
#endif

#if defined(__APPLE__)
#   ifdef __OBJC__
// A standard Objective-C forward declaration when compiling within an Obective-C compilation unit
@class MyCrossPlatformDelegate;
#   else
#       include <objc/objc.h>
// Declare a type alias when compiling in C++
using MyCrossPlatformDelegate = objc_object;
#   endif
#endif

class MyCrossPlatformClass
{
public:
    MyCrossPlatformClass();
    MyCrossPlatformClass(const MyCrossPlatformClass&) = delete;
    MyCrossPlatformClass& operator=(const MyCrossPlatformClass&) = delete;
    ~MyCrossPlatformClass();
    void platformNativeMethod() const;
    void cppMethod() const noexcept;
private:
#if defined(__ANDROID__)
    // Global reference to the Java companion object
    jobject jniObject;
#elif defined(__APPLE__)
    // This also keeps track of the reference
    MyCrossPlatformDelegate* objCObject;
#endif
};

#endif //CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS_HPP
