//
// Created by Gusts Kaksis on 3/6/21.
//

#ifndef CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS2_HPP
#define CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS2_HPP

#include <jni.h>

class MyCrossPlatformClass2
{
public:
    MyCrossPlatformClass2();
    MyCrossPlatformClass2(const MyCrossPlatformClass2&) = delete;
    MyCrossPlatformClass2& operator=(const MyCrossPlatformClass2&) = delete;
    ~MyCrossPlatformClass2();
    void nativeMethod() const;
    void cppMethod() const noexcept;
private:
    jobject jniObject;
};

#endif //CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS2_HPP
