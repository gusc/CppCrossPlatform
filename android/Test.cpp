//
// Created by Gusts Kaksis on 3/8/21.
//

#include "../Test.hpp"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL Java_com_example_cppcrossplatform_Test_runCpp(JNIEnv* env, jobject thiz)
{
    Test t;
    t.run();
}