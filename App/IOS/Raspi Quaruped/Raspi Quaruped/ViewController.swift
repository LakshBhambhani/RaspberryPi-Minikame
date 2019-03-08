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
    
    @IBOutlet weak var textField: UITextField!
    
    var text = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let url = URL(string: "https://192.168.0.36");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        textField.text = "192.168.0.36"
        textField.placeholder = "IP Address of Raspberry Pi"
        text = textField.text!
    }

    @IBAction func bow(_ sender: UIButton) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/bow");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Bowing")
        print("IP Address: " + text)
    }
    
    @IBAction func leanLeft(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/leanLeft");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Leaning Left")
        print("IP Address: " + text)
    }
    
    @IBAction func walkForward(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/walkForward");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Walking Forward")
        print("IP Address: " + text)
    }
    
    @IBAction func leanRight(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/leanRight");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Leaning Right")
        print("IP Address: " + text)
    }
    
    @IBAction func turnLeft(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/turnLeft");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Turning Left")
        print("IP Address: " + text)
    }
    
    @IBAction func homePos(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/homePos");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Switching to Home Position")
        print("IP Address: " + text)
    }
    
    @IBAction func turnRight(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/turnRight");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Turning Right")
        print("IP Address: " + text)
    }
    
    @IBAction func bendBack(_ sender: Any) {
        text = textField.text!
        let url = URL(string: "http://" + text + "/bendBack");
        let request = URLRequest(url: url!);
        webView.loadRequest(request);
        print("Bending Back")
        print("IP Address: " + text)
    }
}

