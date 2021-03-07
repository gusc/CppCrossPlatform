//
// Created by Gusts Kaksis on 3/6/21.
//

#ifndef CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS2_HPP
#define CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS2_HPP

#include <jni.h>

class MyCrossPlatformClass2
{
public:
    MyCrossPlatformClass2(JNIEnv* initJniEnv, jobject initJniObject);
    MyCrossPlatformClass2(const MyCrossPlatformClass2&) = delete;
    MyCrossPlatformClass2& operator=(const MyCrossPlatformClass2&) = delete;
    ~MyCrossPlatformClass2();
    void platformNativeMethod() const;
    void cppMethod() const noexcept;
private:
    JNIEnv* jniEnv { nullptr };
    jobject jniObject;
};

#endif //CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS2_HPP
