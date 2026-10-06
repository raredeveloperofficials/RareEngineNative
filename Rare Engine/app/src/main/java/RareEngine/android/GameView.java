package RareEngine.android;

import android.app.Activity;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.app.AlertDialog;

public class GameView extends SurfaceView implements SurfaceHolder.Callback {

    
    private int surfaceId = -1;
    public boolean runTestScene = false;
    public GameView(final Activity context) {
        super(context);
        context.getActionBar().hide();
        
        context.getWindow().getDecorView().setSystemUiVisibility(
            View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
            | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
            | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
            | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
            | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
            | View.SYSTEM_UI_FLAG_FULLSCREEN
        );
        getHolder().addCallback(this);
        
    }
    
    
    @Override
    public void surfaceCreated(SurfaceHolder holder) {

        Surface surface = holder.getSurface();

        surfaceId = JniAttachment.setUpGLSurface(surface,surfaceId);
        if(runTestScene){JniAttachment.runTestScene(surfaceId);runTestScene=false;}
        JniAttachment.startRenderer(surfaceId);
    }

    @Override
    public void surfaceChanged(
        SurfaceHolder holder,
        int format,
        int width,
        int height) {
            JniAttachment.onSurfaceChanged(surfaceId,width,height);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        JniAttachment.destroyRenderer(surfaceId);
    }
}
