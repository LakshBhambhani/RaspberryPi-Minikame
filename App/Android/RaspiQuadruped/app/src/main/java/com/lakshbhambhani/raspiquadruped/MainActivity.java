package com.lakshbhambhani.raspiquadruped;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.content.Intent;
import android.view.View;
import android.net.Uri;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.webkit.WebSettings;
import android.webkit.*;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    Button walkForward;
    Button turnLeft;
    Button turnRight;
    Button leanRight;
    Button leanLeft;
    Button homePos;
    Button bow;
    Button bendBack;

    Button homePosArm;
    Button grab;
    Button release;
    Button horizontalFront;
    Button verticalFront;
    Button horizontalBack;
    Button verticalBack;

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

        homePosArm = (Button) findViewById(R.id.homePosArm);
        homePosArm.setOnClickListener(this);

        grab = (Button) findViewById(R.id.grab);
        grab.setOnClickListener(this);

        release = (Button) findViewById(R.id.release);
        release.setOnClickListener(this);

        horizontalFront = (Button) findViewById(R.id.horizontalFront);
        horizontalFront.setOnClickListener(this);

        verticalFront = (Button) findViewById(R.id.verticalFront);
        verticalFront.setOnClickListener(this);

        horizontalBack = (Button) findViewById(R.id.horizontalBack);
        horizontalBack.setOnClickListener(this);

        verticalBack = (Button) findViewById(R.id.verticalBack);
        verticalBack.setOnClickListener(this);

        web = (WebView) findViewById(R.id.web);
        WebSettings webSettings = web.getSettings();
        web.getSettings().setLoadWithOverviewMode(true);
        web.getSettings().setUseWideViewPort(true);
        web.getSettings().setBuiltInZoomControls(true);
        web.loadUrl("http://192.168.0.36");
    }

    @Override
    public void onClick(View v) {
        Intent i = null;
        final String myPackage = getPackageName();

        if(v.getId() == R.id.walkForward) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/walkForward");
            System.out.println("Walking Forward Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.turnLeft) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/turnLeft");
            System.out.println("Turning Left Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.turnRight) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/turnRight");
            System.out.println("Turning Right Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.leanRight) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/leanRight");
            System.out.println("Leaning Right Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.leanLeft) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/leanLeft");
            System.out.println("Leaning Left Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.homePos) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/homePos");
            System.out.println("Home Position Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.bow) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/bow");
            System.out.println("Bowing Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.bendBack) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/bendBack");
            System.out.println("Bending Back Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.homePosArm) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/homePosArm");
            System.out.println("Switching to Home Position Arm");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.grab) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/grab");
            System.out.println("Grabbing Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.release) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/release");
            System.out.println("Releasing Triggered");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.horizontalFront) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/horizontalFront");
            System.out.println("Switching to Horizontal Front");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.verticalFront) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/verticalFront");
            System.out.println("Switching to Vertical Front");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.horizontalBack) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/horizontalBack");
            System.out.println("Switching to Horizontal Back");
            System.out.println("URL: " + web.getUrl());
        }

        if(v.getId() == R.id.verticalBack) {
            web.setWebViewClient(new WebViewClient());
            web.loadUrl("http://192.168.0.36/verticalBack");
            System.out.println("Switching to Vertical Back");
            System.out.println("URL: " + web.getUrl());
        }
    }
}
