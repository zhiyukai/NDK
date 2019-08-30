#include <string.h>
#include <jni.h>
#include <stdio.h>
#include <android/log.h>

#define TAG "__BING__" // 这个是自定义的LOG的标识
// 定义LOGD类型
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,__VA_ARGS__)
#define printLog(...) __android_log_print(ANDROID_LOG_INFO, TAG,__VA_ARGS__)

jstring testCallJniString(JNIEnv *env, jobject job) {
  return (*env)->NewStringUTF(env, "Hello from C++");

}

jobject testNewUser(JNIEnv *env, jclass jclazz) {
//获取 Calltest class
  jclass userclass = (*env)->FindClass(env, "prictise/com/myapplication/model/User");
  if (userclass == NULL) {
    printLog("userclass is null");
    return NULL;
  }
  //获取构造方法id
  jmethodID constructor = (*env)->GetMethodID(env, userclass, "<init>", "()V");
  if (NULL == constructor) {
    printLog("can't constructor CallTest");
    return NULL;
  }
  //新建对象 user
  jobject user = (*env)->NewObject(env, userclass, constructor);

  // 初始化对象
  jfieldID filedNameId = (*env)->GetFieldID(env, userclass, "name", "Ljava/lang/String;");
  if (filedNameId == NULL) {
    printLog("filedNameId is null");
  }

  //以下实现 c修改java的string成员变量值
  char *c2j = "初始化值";
  //字符数组c2j转换成jstring类型
  jstring name = (*env)->NewStringUTF(env, c2j);

  (*env)->SetObjectField(env, user, filedNameId, name);

  return user;
}

jstring testGetUserName(JNIEnv *env, jclass jclazz, jobject user) {
//获取 user class
  jclass userclass = (*env)->FindClass(env, "prictise/com/myapplication/model/User");
  if (userclass == NULL) {
    printLog("userclass is null");
  }
  jfieldID filedNameId = (*env)->GetFieldID(env, userclass, "name", "Ljava/lang/String;");
  if (filedNameId == NULL) {
    printLog("filedNameId is null");
  }
  jstring name = (jstring)(*env)->GetObjectField(env, user, filedNameId);
  return name;
}

jint testGetUserAge(JNIEnv *env, jclass jclazz, jobject user) {
//获取 user class
  jclass userclass = (*env)->GetObjectClass(env, user);
  if (userclass == NULL) {
    printLog("userclass is null");
  }
  jfieldID filedAgeId = (*env)->GetFieldID(env, userclass, "age", "I");
  if (filedAgeId == NULL) {
    printLog("filedAgeId is null");
  }
  jint age = (*env)->GetIntField(env, user, filedAgeId);
  return age;
}
jstring testCallGetName(JNIEnv *env, jclass jclazz, jobject user) {
//获取 user class
  jclass userclass = (*env)->GetObjectClass(env, user);
  if (userclass == NULL) {
    printLog("userclass is null");
  }

  // 此时我再调用一下setName
  jmethodID setNameMethodId = (*env)->GetMethodID(env, userclass, "setName", "(Ljava/lang/String;)V");
  if (setNameMethodId == NULL) {
    printLog("setNameMethodId is null");
  }
  //以下实现 c修改java的string成员变量值
  char *c2j = "张三";
  //字符数组c2j转换成jstring类型
  jstring name = (*env)->NewStringUTF(env, c2j);

  (*env)->CallVoidMethod(env, user, setNameMethodId, name);

  jmethodID getNameMethodId = (*env)->GetMethodID(env, userclass, "getName", "()Ljava/lang/String;");
  if (getNameMethodId == NULL) {
    printLog("getNameMethodId is null");
  }
  jstring jname = (jstring)(*env)->CallObjectMethod(env, user, getNameMethodId);

  return jname;
}
jint testCallCallTestAddMethod(JNIEnv *env, jclass jclazz, jint v1, jint v2) {
//获取 user class
  jclass callTestClass = (*env)->FindClass(env, "prictise/com/myapplication/util/CallTest");
  if (callTestClass == NULL) {
    printLog("callTestClass is null");
  }
  jmethodID callTestConstructor = (*env)->GetMethodID(env, callTestClass, "<init>", "()V");
  if (callTestConstructor == NULL) {
    printLog("callTestConstructor is null");
  }

  jobject callTest = (*env)->NewObject(env, callTestClass, callTestConstructor);


  jmethodID addMethodId = (*env)->GetMethodID(env, callTestClass, "add", "(II)I");
  if (addMethodId == NULL) {
    printLog("addMethodId is null");
  }
  jint result = (*env)->CallIntMethod(env, callTest, addMethodId, v1, v2);

  return result;
}

jint testCallCallTestSaddMethod(JNIEnv *env, jclass jclazz, jint v1, jint v2) {
//获取 user class
  jclass callTestClass = (*env)->FindClass(env, "prictise/com/myapplication/util/CallTest");
  if (callTestClass == NULL) {
    printLog("callTestClass is null");
  }

  jmethodID sAddMethodId = (*env)->GetStaticMethodID(env, callTestClass, "sAdd", "(II)I");
  if (sAddMethodId == NULL) {
    printLog("sAddMethodId is null");
  }
  jint result = (*env)->CallStaticIntMethod(env, callTestClass, sAddMethodId, v1, v2);

  return result;
}
jstring testGetCallTestSnameField(JNIEnv *env, jclass jclazz) {
//获取 user class
  jclass callTestClass = (*env)->FindClass(env, "prictise/com/myapplication/util/CallTest");
  if (callTestClass == NULL) {
    printLog("callTestClass is null");
  }

  jfieldID sNameStaticFieldID = (*env)->GetStaticFieldID(env, callTestClass, "sName", "Ljava/lang/String;");
  if (sNameStaticFieldID == NULL) {
    printLog("sNameStaticFieldID is null");
  }
  char *sNameSet = "我是静态属性";
  jstring nameSet = (*env)->NewStringUTF(env, sNameSet);
  (*env)->SetStaticObjectField(env, callTestClass, sNameStaticFieldID, nameSet);

  jstring result = (*env)->GetStaticObjectField(env, callTestClass, sNameStaticFieldID);

  return result;
}

jstring testGetJniUser(JNIEnv *env, jclass jclazz, jobject user) {
//获取 user class
  jclass callTestClass = (*env)->FindClass(env, "prictise/com/myapplication/util/CallTest");
  if (callTestClass == NULL) {
    printLog("callTestClass is null");
  }

  jmethodID callTestCoustructorID = (*env)->GetMethodID(env, callTestClass, "<init>", "()V");
  if (callTestCoustructorID == NULL) {
    printLog("callTestCoustructorID is null");
  }

  jobject callTest = (*env)->NewObject(env, callTestClass, callTestCoustructorID);

  jmethodID getUserMethodID =
      (*env)->GetMethodID(env, callTestClass, "getUser", "(Lprictise/com/myapplication/model/User;)Ljava/lang/String;");

  if (getUserMethodID == NULL) {
    printLog("getUserMethodID is null");
  }
  jstring result = (*env)->CallObjectMethod(env, callTest, getUserMethodID, user);
  printLog("%d ",GetCurrentThreadId());

  return result;
}


JNINativeMethod gMethods[] = {
    {"callJniString", "()Ljava/lang/String;", (void *) testCallJniString},
    {"newUser", "()Lprictise/com/myapplication/model/User;", (void *) testNewUser},
    {"getUserName", "(Lprictise/com/myapplication/model/User;)Ljava/lang/String;", (void *) testGetUserName},
    {"getUserAge", "(Lprictise/com/myapplication/model/User;)I", (void *) testGetUserAge},
    {"callGetName", "(Lprictise/com/myapplication/model/User;)Ljava/lang/String;", (void *) testCallGetName},
    {"callCallTestAddMethod", "(II)I", (void *) testCallCallTestAddMethod},
    {"callCallTestSaddMethod", "(II)I", (void *) testCallCallTestSaddMethod},
    {"getCallTestSnameField", "()Ljava/lang/String;", (void *) testGetCallTestSnameField},
    {"getJniUser", "(Lprictise/com/myapplication/model/User;)Ljava/lang/String;", (void *) testGetJniUser}
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
  jclass jcl = (*env)->FindClass(env, "prictise/com/myapplication/util/CalledUtil");
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