package com.lakshbhambhani.raspiquadruped;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.content.Intent;
import android.view.View;
import android.net.Uri;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    Button walkForward;
    Button turnLeft;
    Button turnRight;
    Button leanRight;
    Button leanLeft;
    Button homePos;
    Button bow;
    Button bendBack;

    WebView web;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        walkForward = (Button) findViewById(R.id.walkForward);
        walkForward.setOnClickListener(this);

        turnLeft = (Button) findViewById(R.id.turnLeft);
        turnLeft.setOnClickListener(this);

        turnRight = (Button) findViewById(R.id.turnRight);
        turnRight.setOnClickListener(this);

        leanRight = (Button) findViewById(R.id.leanRight);
        leanRight.setOnClickListener(this);

        leanLeft = (Button) findViewById(R.id.leanLeft);
        leanLeft.setOnClickListener(this);

        homePos = (Button) findViewById(R.id.homePos);
        homePos.setOnClickListener(this);

        bow = (Button) findViewById(R.id.bow);
        bow.setOnClickListener(this);

        bendBack = (Button) findViewById(R.id.bendBack);
        bendBack.setOnClickListener(this);

        web = (WebView) findViewById(R.id.web);
        web.loadUrl("https://www.google.com");
    }

    @Override
    public void onClick(View v) {
        Intent i = null;
        final String myPackage = getPackageName();

        if(v.getId() == R.id.walkForward) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/walkForward");
            System.out.println("Walking Forward Triggered");
        }

        if(v.getId() == R.id.turnLeft) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/turnLeft");
            System.out.println("Turning Left Triggered");
        }

        if(v.getId() == R.id.turnRight) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/turnRight");
            System.out.println("Turning Right Triggered");
        }

        if(v.getId() == R.id.leanRight) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/leanRight");
            System.out.println("Leaning Right Triggered");
        }

        if(v.getId() == R.id.leanLeft) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/leanLeft");
            System.out.println("Leaning Left Triggered");
        }

        if(v.getId() == R.id.homePos) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/homePos");
            System.out.println("Home Position Triggered");
        }

        if(v.getId() == R.id.bow) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/bow");
            System.out.println("Bowing Triggered");
        }

        if(v.getId() == R.id.bendBack) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("192.168.0.36/bendBack");
            System.out.println("Bending Back Triggered");
        }
    }
}
