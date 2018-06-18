#include "prictise_com_myapplication_model_JniTest.h"
JNIEXPORT jstring JNICALL Java_prictise_com_myapplication_model_JniTest_getString
  (JNIEnv *env, jobject job){

    return (*env)->NewStringUTF(env, "hello world");
}
