#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prictise_com_myapplication_ndkImage_NdkImageUtils.h"

/*
 * Class:     prictise_com_myapplication_ndkImage_NdkImageUtils
 * Method:    getNdkBitmap
 * Signature: ([III)[I
 */
JNIEXPORT jintArray JNICALL Java_prictise_com_myapplication_ndkImage_NdkImageUtils_getNdkBitmap
        (JNIEnv *env, jclass jclazz, jintArray jarray, jint jwidth, jint jheight) {
    jint *source = (*env)->GetIntArrayElements(env, jarray, 0);
    float brightness = 0.2f; // 亮度
    float contrainst = 0.2f; // 对比度
    int a, r, g, b;
    int bab = (int) (255 * brightness);
    float ca = 1.0f + contrainst;

    for (int i = 0; i < jwidth; i++) {
        for (int j = 0; j < jheight; j++) {
            int color = source[jwidth * j + i];
            a = color >> 24;
            r = (color >> 16) & 0xff;
            g = (color >> 8) & 0xff;
            b = color & 0xff;

            // 美白
            int ri = r + bab;
            int gi = g + bab;
            int bi = b + bab;

            // 边界检测
            r = ri > 255 ? 255 : (ri < 0 ? 0 : ri);
            g = gi > 255 ? 255 : (gi < 0 ? 0 : gi);
            b = bi > 255 ? 255 : (bi < 0 ? 0 : bi);

            // 再在美白的基础上使得黑的更黑，白的更白
            // 扩大对比度
            ri = r - 128;
            gi = g - 128;
            bi = b - 128;

            ri = (int) (ri * ca);
            gi = (int) (gi * ca);
            bi = (int) (bi * ca);

            ri = r + 128;
            gi = g + 128;
            bi = b + 128;

            // 边界检测
            r = ri > 255 ? 255 : (ri < 0 ? 0 : ri);
            g = gi > 255 ? 255 : (gi < 0 ? 0 : gi);
            b = bi > 255 ? 255 : (bi < 0 ? 0 : bi);

            source[jwidth * j + i] = (a << 24) | (r << 16) | (g << 8) | b;
        }
    }

    int newSize = jwidth * jheight;
    jintArray result = (*env)->NewIntArray(env, newSize);
    (*env)->SetIntArrayRegion(env, result, 0, newSize, source);
    // 释放资源
    (*env)->ReleaseIntArrayElements(env, jarray, source, 0);

    return result;
}
