package com.example.cppcrossplatform;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    static {
        // Explicitly load our libraries before we start doing everything else
        System.loadLibrary("CppCrossPlatform");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Test t = new Test();
        t.run();
    }
}