package prictise.com.myapplication.javaImage;

import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.Color;

/**
 * @author zhisiyi
 * @date 2017年1月7日 下午2:19:40
 * @comment
 */
public class JavaImageUtils {

	public static final float brightness = 0.2f;// 亮度
	public static final float contrainst = 0.2f;// 对比度

	public static Bitmap getImageBitmap(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		Bitmap result = Bitmap.createBitmap(width, height, Config.RGB_565);
		int a, r, g, b;
		int bab = (int) (255 * brightness);
		float ca = 1.0f + contrainst;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				int color = bitmap.getPixel(i, j);
				a = Color.alpha(color);
				r = Color.red(color);
				g = Color.green(color);
				b = Color.blue(color);

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

				result.setPixel(i, j, Color.argb(a, r, g, b));
			}
		}
		return result;
	}

}
