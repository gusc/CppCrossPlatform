package com.example.cppcrossplatform;

public class Test {

    private native void runCpp();

    private void testJavaMaster()
    {
        MyCrossPlatformClass2 cls2 = new MyCrossPlatformClass2();
        cls2.nativeMethod();
        cls2.cppMethod();
        cls2.Dispose();
    }

    public void run()
    {
        testJavaMaster();
        runCpp();
    }
}
