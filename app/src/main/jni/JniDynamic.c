#include <string.h>
#include <jni.h>
#include <stdio.h>
#include <android/log.h>

#define TAG "__BING__" // 这个是自定义的LOG的标识
// 定义LOGD类型
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,__VA_ARGS__)

jstring testDynamicGetName(JNIEnv *env, jobject job) {
  return (*env)->NewStringUTF(env, "动态注册终于成功啦");
}
static JNINativeMethod gMethods[] = {
    {"getDynamicRegStirng", "()Ljava/lang/String;", (void *) testDynamicGetName}
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
  __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "sizeof(gMethods) = %u", sizeof(gMethods));
  __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "sizeof(gMethods[0]) = %lu", sizeof(gMethods[0]));

  if ((*env)->RegisterNatives(env, jcl, gMethods, (sizeof(gMethods) / sizeof(gMethods[0]))) <
      0) {
    __android_log_print(ANDROID_LOG_DEBUG, "__BING__", "register native method failed");
    return -1;
  }
  LOGD("--------JNI_OnLoad-12---- %d ", 2);
  env = NULL;
  return JNI_VERSION_1_6;
}

//当动态库被卸载时这个函数被系统调用
JNICALL void JNI_OnUnload(JavaVM *vm, void *reserved) {
  LOGD("JNI_OnUnload %d", 2);
}