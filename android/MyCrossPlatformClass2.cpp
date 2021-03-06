//
// Created by Gusts Kaksis on 3/6/21.
//

#include "MyCrossPlatformClass2.hpp"
#include "Utilities/JniHelpers.hpp"

#include <stdexcept>
#include <iostream>

namespace
{

JNIEnv* jniEnv;
void cppMethodCall(JNIEnv* jniEnv, jobject thisRef)
{
    // Java has called cppmethod
    auto* nativeObject = getPtr<MyCrossPlatformClass2>(jniEnv, thisRef);
    nativeObject->cppMethod();
}
const JNINativeMethod methodsArray[] =
{
    { "cppMethod", "()V", reinterpret_cast<void*>(&cppMethodCall) }
};

}

MyCrossPlatformClass2::MyCrossPlatformClass2()
{
    auto javaClass = jniEnv->FindClass("com/example/cppcrossplatform/MyCrossPlatformClass2");
    if (!javaClass)
    {
        throw std::runtime_error("Failed to find MyCrossPlatformClass2 in JNI environment");
    }
    auto constructorId = jniEnv->GetMethodID(javaClass, "<init>", "(J)V");
    if (!constructorId)
    {
        throw std::runtime_error("Failed to find MyCrossPlatformClass2 constructor");
    }
    // Create object and pass this pointer as it's first argument for storage
    jniObject = jniEnv->NewObject(javaClass, constructorId, reinterpret_cast<jlong>(this));
    if (!jniObject)
    {
        throw std::runtime_error("Failed to create MyCrossPlatformClass2");
    }
}

MyCrossPlatformClass2::~MyCrossPlatformClass2()
{
    // Release the global reference
    jniEnv->DeleteGlobalRef(jniObject);
}

void MyCrossPlatformClass2::nativeMethod() const
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

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* /* reserved */)
{
    // Capture current environment for later use
    if (vm->GetEnv(reinterpret_cast<void**>(&jniEnv), JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_ERR;
    }
    // Find the class definition in the current environment
    auto javaClass = jniEnv->FindClass("com/example/cppcrossplatform/MyCrossPlatformClass2");
    if (!javaClass)
    {
        return JNI_ERR;
    }
    // Register method map for the class
    if (jniEnv->RegisterNatives(javaClass, methodsArray, sizeof(methodsArray) / sizeof(methodsArray[0])) < 0)
    {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}