//
// Created by Gusts Kaksis on 3/6/21.
//

#include "../MyCrossPlatformClass.hpp"
#include "Utilities/JniHelpers.hpp"

#include <stdexcept>

namespace
{

JNIEnv* jniEnv;
void cppMethodCall(JNIEnv* jniEnv, jobject thisRef)
{
    // Java has called native cppMethod
    auto* nativeObject = getNativePtr<MyCrossPlatformClass>(jniEnv, thisRef);
    nativeObject->cppMethod();
}
// Method map for MyCrossPlatformClass in Java
const JNINativeMethod methodsArray[] =
{
    { "cppMethod", "()V", reinterpret_cast<void*>(&cppMethodCall) }
};

}

MyCrossPlatformClass::MyCrossPlatformClass()
{
    auto javaClass = jniEnv->FindClass("com/example/cppcrossplatform/MyCrossPlatformClass");
    if (!javaClass)
    {
        throw std::runtime_error("Failed to find MyCrossPlatformClass in JNI environment");
    }
    auto constructorId = jniEnv->GetMethodID(javaClass, "<init>", "(J)V");
    if (!constructorId)
    {
        throw std::runtime_error("Failed to find MyCrossPlatformClass constructor");
    }
    // Create object and pass this pointer as it's first argument for storage
    auto localObject = jniEnv->NewObject(javaClass, constructorId, reinterpret_cast<jlong>(this));
    if (!localObject)
    {
        throw std::runtime_error("Failed to create MyCrossPlatformClass");
    }
    // Last but not least we need to create global reference so we can keep owning the Java companion class
    jniObject = jniEnv->NewGlobalRef(localObject);
}

MyCrossPlatformClass::~MyCrossPlatformClass()
{
    // Release the global reference
    jniEnv->DeleteGlobalRef(jniObject);
}

void MyCrossPlatformClass::platformNativeMethod() const
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

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* /* reserved */)
{
    // Capture current environment for later use
    if (vm->GetEnv(reinterpret_cast<void**>(&jniEnv), JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_ERR;
    }
    // Find the class definition in the current environment
    auto javaClass = jniEnv->FindClass("com/example/cppcrossplatform/MyCrossPlatformClass");
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