//
// Created by Gusts Kaksis on 3/6/21.
//

#include "MyCrossPlatformClass2.hpp"
#include "Utilities/JniHelpers.hpp"

#include <stdexcept>
#include <iostream>

MyCrossPlatformClass2::MyCrossPlatformClass2(JNIEnv* initJniEnv, jobject initJniObject)
    : jniEnv(initJniEnv)
    // Immediatelly create a global reference so we don't loose it
    , jniObject(initJniEnv->NewGlobalRef(initJniObject))
{}

MyCrossPlatformClass2::~MyCrossPlatformClass2()
{
    // Release the global reference
    jniEnv->DeleteGlobalRef(jniObject);
}

void MyCrossPlatformClass2::platformNativeMethod() const
{
    auto javaClass = jniEnv->FindClass("com/example/cppcrossplatform/MyCrossPlatformClass2");
    if (!javaClass)
    {
        throw std::runtime_error("Failed to find MyCrossPlatformClass2 in JNI environment");
    }
    auto methodId = jniEnv->GetMethodID(javaClass, "nativeMethod", "()V");
    if (!methodId)
    {
        throw std::runtime_error("Failed to find nativeMethod in MyCrossPlatformClass2");
    }
    jniEnv->CallVoidMethod(jniObject, methodId);
}

void MyCrossPlatformClass2::cppMethod() const noexcept
{
    std::cout << "C++ method called\n";
}

extern "C" JNIEXPORT jlong JNICALL Java_com_example_cppcrossplatform_MyCrossPlatformClass2_constructNative(JNIEnv* jniEnv, jobject thisRef)
{
    // Create global reference
    auto* nativeObject = new MyCrossPlatformClass2(jniEnv, thisRef);
    return reinterpret_cast<jlong>(nativeObject);
}

extern "C" JNIEXPORT void JNICALL Java_com_example_cppcrossplatform_MyCrossPlatformClass2_destructNative(JNIEnv* jniEnv, jobject thisRef)
{
    // Java has asked us to delete the C++ object
    auto* nativeObject = getNativePtr<MyCrossPlatformClass2>(jniEnv, thisRef);
    delete nativeObject;
}

extern "C" JNIEXPORT void JNICALL Java_com_example_cppcrossplatform_MyCrossPlatformClass2_cppMethod(JNIEnv* jniEnv, jobject thisRef)
{
    // Java has called cppmethod
    auto* nativeObject = getNativePtr<MyCrossPlatformClass2>(jniEnv, thisRef);
    nativeObject->cppMethod();
}
