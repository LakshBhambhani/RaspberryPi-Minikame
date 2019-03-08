//
//  ViewController.swift
//  Raspi Quaruped
//
//  Created by Laksh Bhambhani on 3/6/19.
//  Copyright © 2019 Laksh Bhambhani. All rights reserved.
//

import UIKit
import WebKit

class ViewController: UIViewController, WKUIDelegate {
    
    @IBOutlet weak var webView: UIWebView!
   
    @IBOutlet weak var bow: UIButton!
    @IBOutlet weak var leanLeft: UIButton!
    @IBOutlet weak var walkForward: UIButton!
    @IBOutlet weak var leanRIght: UIButton!
    @IBOutlet weak var turnLeft: UIButton!
    @IBOutlet weak var homePos: UIButton!
    @IBOutlet weak var turnRight: UIButton!
    @IBOutlet weak var bendBack: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let url = URL(string: "https://192.168.0.36");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
    }

    @IBAction func bow(_ sender: UIButton) {
        let url = URL(string: "http://192.168.0.36/bow");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Bowing")
    }
    
    @IBAction func leanLeft(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/leanLeft");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Leaning Left")
    }
    
    @IBAction func walkForward(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/walkForward");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Walking Forward")
    }
    
    @IBAction func leanRight(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/leanRight");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Leaning Right")
    }
    
    @IBAction func turnLeft(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/turnLeft");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Turning Left")
    }
    
    @IBAction func homePos(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/homePos");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Switching to Home Position")
    }
    
    @IBAction func turnRight(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/turnRight");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Turning Right")
    }
    
    @IBAction func bendBack(_ sender: Any) {
        let url = URL(string: "http://192.168.0.36/bendBack");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Bending Back")
    }
}

