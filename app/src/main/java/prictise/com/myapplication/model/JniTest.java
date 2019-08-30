package prictise.com.myapplication.model;

/**
 * @author zhisiyi
 * @date 18.6.18 0:36
 * @comment
 */
public class JniTest {

  static {
    System.loadLibrary("testSo");
  }

  public native String getString();

  public native String testShengCheng();
}
