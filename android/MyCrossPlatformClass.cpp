//
// Created by Gusts Kaksis on 3/6/21.
//

#include "../MyCrossPlatformClass.hpp"
#include "Utilities/JniHelpers.hpp"

#include <stdexcept>

MyCrossPlatformClass::MyCrossPlatformClass(JNIEnv* initJniEnv, jobject initJniObject)
    : jniEnv(initJniEnv)
    // Immediatelly create a global reference so we don't loose it
    , jniObject(initJniEnv->NewGlobalRef(initJniObject))
{}

MyCrossPlatformClass::~MyCrossPlatformClass()
{
    // Release the global reference
    jniEnv->DeleteGlobalRef(jniObject);
}

void MyCrossPlatformClass::nativeMethod() const
{
    auto javaClass = jniEnv->FindClass("com/example/cppcrossplatform/MyCrossPlatformClass");
    if (!javaClass)
    {
        throw std::runtime_error("Failed to find MyCrossPlatformClass in JNI environment");
    }
    auto methodId = jniEnv->GetMethodID(javaClass, "nativeMethod", "()V");
    if (!methodId)
    {
        throw std::runtime_error("Failed to find nativeMethod in MyCrossPlatformClass");
    }
    jniEnv->CallVoidMethod(jniObject, methodId);
}

extern "C" JNIEXPORT jlong JNICALL Java_com_example_cppcrossplatform_MyCrossPlatformClass_constructNative(JNIEnv* jniEnv, jobject thisRef)
{
    // Create global reference
    auto* nativeObject = new MyCrossPlatformClass(jniEnv, thisRef);
    return reinterpret_cast<jlong>(nativeObject);
}

extern "C" JNIEXPORT void JNICALL Java_com_example_cppcrossplatform_MyCrossPlatformClass_destructNative(JNIEnv* jniEnv, jobject thisRef)
{
    // Java has asked us to delete the C++ object
    auto* nativeObject = getPtr<MyCrossPlatformClass>(jniEnv, thisRef);
    delete nativeObject;
}

extern "C" JNIEXPORT void JNICALL Java_com_example_cppcrossplatform_MyCrossPlatformClass_cppMethod(JNIEnv* jniEnv, jobject thisRef)
{
    // Java has called cppmethod
    auto* nativeObject = getPtr<MyCrossPlatformClass>(jniEnv, thisRef);
    nativeObject->cppMethod();
}
