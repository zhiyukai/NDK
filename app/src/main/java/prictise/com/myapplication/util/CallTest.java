package prictise.com.myapplication.util;

import android.util.Log;
import prictise.com.myapplication.model.User;

/**
 * Created by zhangshiyu on 2017/11/24.
 */

public class CallTest {

  private static final String TAG = "CallTest";
  /**
   * no-static field
   */
  private String name = "calltest_name";
  /**
   * static field
   */
  public static String sName = "static calltest_name";


  /**
   * no-static method
   */
  public int add(int value1, int value2) {
    return value1 + value2;
  }

  /**
   * static method
   */
  public static int sAdd(int value1, int value2) {
    return value1 + value2;
  }

  /**
   * void method
   */
  public void show(String msg1, int count) {
    Log.i(TAG, msg1 + count);
  }

  /**
   * reference type
   */
  public String getUser(User user) {
    return "User-- name:" + user.getName() + ",age:" + user.getAge();
  }


}
