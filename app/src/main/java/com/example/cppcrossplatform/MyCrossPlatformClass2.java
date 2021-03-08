package com.example.cppcrossplatform;

import android.util.Log;

/**
 * This is an example of master Java class that creates a companion C++ object
 */
public class MyCrossPlatformClass2 {
    // This member will hold a raw pointer value of the companion C++ object
    private long nativePtr;
    // This method constructs the C++ object and returns
    // raw pointer that get's stored in nativePtr member
    private native long constructNative();
    // This method destroys the C++ object
    private native void destructNative();

    MyCrossPlatformClass2() {
        nativePtr = constructNative();
    }
    void Dispose() {
        destructNative();
    }

    public void nativeMethod() {
        Log.d("Example", "Java method called");
    }
    public native void cppMethod();
}
