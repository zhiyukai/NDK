package prictise.com.myapplication.model;

/**
 * @author zhisiyi
 * @date 18.6.18 21:03
 * @comment
 */
public class JniDynamicReg {
    static {
        System.loadLibrary("dynamicReg");
    }
    public native String getDynamicRegStirng();
}
