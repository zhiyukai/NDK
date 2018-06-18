package prictise.com.myapplication.ndkImage;

/**
 * @author zhisiyi
 * @date 18.6.18 0:36
 * @comment
 */
public class NdkImageUtils {
    static{
        System.loadLibrary("TuPianMeiBai");
    }
    public static native int[] getNdkBitmap(int[] buffer, int width, int height);
}
