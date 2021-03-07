//
// Created by Gusts Kaksis on 3/6/21.
//

#ifndef CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS_HPP
#define CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS_HPP

#if defined(__ANDROID__)
#   include <jni.h>
#endif

class MyCrossPlatformClass
{
public:
#if defined(__ANDROID__)
    MyCrossPlatformClass(JNIEnv* initJniEnv, jobject initJniObject);
#endif
    MyCrossPlatformClass(const MyCrossPlatformClass&) = delete;
    MyCrossPlatformClass& operator=(const MyCrossPlatformClass&) = delete;
    ~MyCrossPlatformClass();
    void platformNativeMethod() const;
    void cppMethod() const noexcept;
private:
#if defined(__ANDROID__)
    JNIEnv* jniEnv { nullptr };
    jobject jniObject;
#endif
};

#endif //CPPCROSSPLATFORM_MYCROSSPLATFORMCLASS_HPP
