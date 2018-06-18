   LOCAL_PATH := $(call my-dir)

   include $(CLEAR_VARS)
   LOCAL_MODULE    := testSo
   LOCAL_SRC_FILES := prictise_com_myapplication_model_JniTest.c

   LOCAL_MODULE    := TuPianMeiBai
   LOCAL_SRC_FILES := prictise_com_myapplication_ndkImage_NdkImageUtils.c

   LOCAL_MODULE    := dynamicReg
   LOCAL_SRC_FILES := JniDynamic.c
   LOCAL_LDFLAGS += -llog
   include $(BUILD_SHARED_LIBRARY)