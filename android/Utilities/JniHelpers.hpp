//
// Created by Gusts Kaksis on 3/6/21.
//

#ifndef CPPCROSSPLATFORM_JNIHELPERS_HPP
#define CPPCROSSPLATFORM_JNIHELPERS_HPP

#include <jni.h>

// This method will return the raw C++ pointer stored
// in the nativePtr member of the Java object
template<typename T>
T* getPtr(JNIEnv* jniEnv, jobject ptrThis)
{
    // First we need to get the class definition of the object
    jclass javaClass = jniEnv->GetObjectClass(ptrThis);
    if (!javaClass)
    {
        jniEnv->FatalError("GetObjectClass failed");
    }
    // Now we find the field ID
    jfieldID nativePtrId = jniEnv->GetFieldID(javaClass, "nativePtr", "J");
    if (!nativePtrId)
    {
        jniEnv->FatalError("GetFieldID failed");
    }
    // And now we read the pointer value, cast it and return it
    jlong nativePtr = jniEnv->GetLongField(ptrThis, nativePtrId);
    return reinterpret_cast<T*>(nativePtr);
}

#endif //CPPCROSSPLATFORM_JNIHELPERS_HPP
