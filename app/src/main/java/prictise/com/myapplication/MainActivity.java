package prictise.com.myapplication;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import prictise.com.myapplication.javaImage.JavaImageUtils;
import prictise.com.myapplication.model.JniDynamicReg;
import prictise.com.myapplication.model.JniTest;
import prictise.com.myapplication.ndkImage.NdkImageUtils;

/**
 * @author zhisiyi
 * @date 18.6.18 0:36
 * @comment
 */
public class MainActivity extends Activity implements View.OnClickListener {

    private ImageView mYuanTuIV;
    private Button mYuanBt, mJavaBt, mNdkBt;
    private Bitmap mSource;
    private TextView mNameTV;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mYuanTuIV = (ImageView) findViewById(R.id.iv_resource);
        mNameTV = (TextView) findViewById(R.id.tv_name);
        findViewById(R.id.bt_yuan).setOnClickListener(this);
        findViewById(R.id.bt_java).setOnClickListener(this);
        findViewById(R.id.bt_ndk).setOnClickListener(this);
        JniDynamicReg jniDynamicReg = new JniDynamicReg();
        mNameTV.setText(jniDynamicReg.getDynamicRegStirng());
        mSource = BitmapFactory.decodeResource(getResources(), R.mipmap.psb);
    }

    @Override
    public void onClick(View v) {
        if (v == null)
            return;
        switch (v.getId()) {
            case R.id.bt_yuan:
                showResourcePic();
                break;
            case R.id.bt_java:
                javaIamge();
                break;
            case R.id.bt_ndk:
                ndkImage();
                break;
            default:
                break;
        }

    }

    private void ndkImage() {
        long start = System.currentTimeMillis();
        int width = mSource.getWidth();
        int heigth = mSource.getHeight();
        int buffer[] = new int[width * heigth];
        mSource.getPixels(buffer, 0, width, 0, 0, width - 1, heigth - 1);
        int[] ndkImage = NdkImageUtils.getNdkBitmap(buffer, width, heigth);
        Bitmap bitmap = Bitmap.createBitmap(ndkImage, width, heigth, Bitmap.Config.RGB_565);
        mYuanTuIV.setImageBitmap(bitmap);
        long end = System.currentTimeMillis();
        Toast.makeText(this, (end - start) + "", Toast.LENGTH_SHORT).show();
    }

    private void javaIamge() {
        long start = System.currentTimeMillis();
        mYuanTuIV.setImageBitmap(JavaImageUtils.getImageBitmap(mSource));
        long end = System.currentTimeMillis();
        Toast.makeText(this, (end - start) + "", Toast.LENGTH_SHORT).show();
    }

    private void showResourcePic() {
        mYuanTuIV.setImageBitmap(mSource);
    }
}
