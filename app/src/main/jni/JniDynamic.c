#include <string.h>
#include <jni.h>
#include <stdio.h>
#include <android/log.h>

#define TAG "result" // 这个是自定义的LOG的标识

jstring testDynamicGetName(JNIEnv *env, jobject job) {
    return (*env)->NewStringUTF(env, "动态注册终于成功啦");
}
static JNINativeMethod gMethods[] = {
        {"getDynamicRegStirng", "()Ljava/lang/String;", (void *)testDynamicGetName}
};

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL; //注册时在JNIEnv中实现的，所以必须首先获取它
    jint result = -1;
    __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "--------JNI_OnLoad-----");
    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "--------GetEnv-----");
        return -1;
    }
    if (env == NULL) {
        __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "error3");
        return -1;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "error1");
    jclass jcl = (*env)->FindClass(env, "prictise/com/myapplication/model/JniDynamicReg");
    __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "error2");
    if (jcl == NULL) {
        __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "error");
        return -1;
    }

    if ((*env)->RegisterNatives(env, jcl, gMethods, (sizeof(gMethods) / sizeof(gMethods[0]))) <
        0) {
        __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "register native method failed");
        return -1;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "--------JNI_OnLoad-12----");
    env = NULL;
    return JNI_VERSION_1_6;
}