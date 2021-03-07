package com.example.cppcrossplatform;

import android.util.Log;

/**
 * This is an example of a companion Java class that is created from C++
 */
public class MyCrossPlatformClass {
    // This member will hold a raw pointer value of the companion C++ object
    private long nativePtr;

    MyCrossPlatformClass(long initNativePtr) {
        nativePtr = initNativePtr;
    }

    private void nativeMethod() {
        Log.d("Example", "Java method called");
    }
    private native void cppMethod();
}
