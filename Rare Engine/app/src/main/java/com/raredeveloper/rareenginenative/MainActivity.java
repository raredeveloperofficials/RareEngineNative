package com.raredeveloper.rareenginenative;

import RareEngine.android.GameView;
import RareEngine.android.JniAttachment;
import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.SpannableStringBuilder;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;


public class MainActivity extends Activity {

    @Override
    public void onPointerCaptureChanged(boolean hasCapture) {
    }
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout ll = new LinearLayout(this);
        ll.setOrientation(LinearLayout.VERTICAL);
        final ScrollView sv = new ScrollView(this);
        final TextView tv = new TextView(this);
        tv.setText("Log:");
        tv.setBackgroundColor(Color.GRAY);
        sv.addView(tv,new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,ViewGroup.LayoutParams.WRAP_CONTENT));
        ll.addView(sv,new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,(int)getResources().getDisplayMetrics().density*100));
        new Handler().postDelayed(new Runnable() {
                @Override
                public void run() {
                    String log = JniAttachment.getLog();
                    String s = "\n" + log;

                    if (!log.equals("")) {

                        SpannableString spannable = new SpannableString(s);

                        String[] lines = s.split("\n", -1);
                        int position = 0;

                        for (String line : lines) {
                            if (line.startsWith("Rare Engine:")) {
                                spannable.setSpan(
                                    new ForegroundColorSpan(Color.WHITE),
                                    position,
                                    position + line.length(),
                                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE
                                );
                            }
                            if (line.startsWith("Error:")) {
                                spannable.setSpan(
                                    new ForegroundColorSpan(Color.RED),
                                    position,
                                    position + line.length(),
                                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE
                                );
                            }
                            if (line.startsWith("Warning:")) {
                                spannable.setSpan(
                                    new ForegroundColorSpan(Color.YELLOW),
                                    position,
                                    position + line.length(),
                                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE
                                );
                            }
                            position += line.length() + 1; // +1 for '\n'
                        }
                        SpannableStringBuilder result =
                            new SpannableStringBuilder(tv.getText());

                        result.append(spannable);

                        tv.setText(result);
                        

                        sv.post(new Runnable() {
                                @Override
                                public void run() {
                                    sv.fullScroll(View.FOCUS_DOWN);
                                }
                            });
                    }

                    new Handler().postDelayed(this, 500);
                }
            }, 500);
        GameView  game = new GameView(this);
        game.runTestScene = true;
        ll.addView(game,new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,LinearLayout.LayoutParams.MATCH_PARENT));
        setContentView(ll);
        
    }
}
