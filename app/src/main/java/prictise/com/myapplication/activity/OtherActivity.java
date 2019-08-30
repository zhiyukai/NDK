package prictise.com.myapplication.activity;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.TextView;
import prictise.com.myapplication.R;
import prictise.com.myapplication.model.User;
import prictise.com.myapplication.util.CalledUtil;

/**
 * @Author zhisiyi
 * @Date 2019.08.18 16:23
 * @Comment
 */
public class OtherActivity extends Activity {


  String uriString, host, source;
  TextView tv, tschema;
  User user = new User();

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_other);
    //schema of
    tschema = (TextView) findViewById(R.id.schame);
    Intent intent = getIntent();
    String scheme = intent.getScheme();
    if (scheme != null) {
      Uri uri = intent.getData();
      if (uri != null) {
        uriString = uri.toString();
        host = uri.getHost();
      }
      source = uri.getQueryParameter("source");
      tschema.setText("path:" + uriString + "\n" + "source param:" + source);
    }
    // Example of a call to a native method
    tv = (TextView) findViewById(R.id.sample_text);
    user.setName("java name");
    user.setAge(20);
    StringBuilder stringBuilder = new StringBuilder();
    stringBuilder.append("Test:" + CalledUtil.callJniString());
    stringBuilder.append("\nnewUser:" + CalledUtil.newUser().toString());
    stringBuilder.append("\ngetUserName:" + CalledUtil.getUserName(user));
    stringBuilder.append("\ngetUserAge:" + CalledUtil.getUserAge(user));
    stringBuilder.append("\ncallGetName:" + CalledUtil.callGetName(user));
    stringBuilder.append("\ncallCallTestAddMethod:12+13=" + CalledUtil.callCallTestAddMethod(12, 13));
    stringBuilder.append("\ncallCallTestSaddMethod:15+16=" + CalledUtil.callCallTestSaddMethod(15, 16));
    stringBuilder.append("\ngetCallTestSnameField:" + CalledUtil.getCallTestSnameField());
    stringBuilder.append("\ngetJniUser:" + CalledUtil.getJniUser(user));
    tv.setText(stringBuilder.toString());
  }
}
