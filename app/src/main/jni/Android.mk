   LOCAL_PATH := $(call my-dir)

   include $(CLEAR_VARS)
   LOCAL_MODULE    := Test
   LOCAL_SRC_FILES := prictise_com_myapplication_model_JniTest.c
   LOCAL_LDFLAGS += -llog
   include $(BUILD_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE    := calljava
   LOCAL_SRC_FILES := CallTest.c
   LOCAL_LDFLAGS += -llog
   include $(BUILD_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE    := TuPianMeiBai
   LOCAL_SRC_FILES := prictise_com_myapplication_ndkImage_NdkImageUtils.c
   LOCAL_LDFLAGS += -llog
   include $(BUILD_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE    := dynamicReg
   LOCAL_SRC_FILES := JniDynamic.c
   #找到app下libs目录（即上图中上面的红框位置），不写路径会找不到，${TARGET_ARCH_ABI} 表示平台目录
   #这一块不写好像也可以找到
   #LOCAL_SRC_FILES := ../../../../libs/${TARGET_ARCH_ABI}/libfmodL.so
   LOCAL_LDFLAGS += -llog
   include $(BUILD_SHARED_LIBRARY)