package RareEngine.android;
import android.view.Surface;

public class JniAttachment {
    
    static {
        System.loadLibrary("android-attachment");
    }
    public static native String helloFromJNI();
    public static native String getLog();
    public static native int setUpGLSurface(Surface surface,int sid);
    public static native void startRenderer(int surfaceid);
    public static native void destroyRenderer(int surfaceid);
    public static native void runTestScene(int surfaceid);
    public static native void onSurfaceChanged(int surfaceid,int width,int height);
}
