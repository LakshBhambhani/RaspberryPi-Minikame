//
//  ViewController.swift
//  Raspi Quaruped
//
//  Created by Laksh Bhambhani on 3/6/19.
//  Copyright © 2019 Laksh Bhambhani. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var webView: UIWebView!

    override func viewDidLoad() {
        super.viewDidLoad()
        self.webView.loadRequest(URLRequest(url:URL(string: "https://www.google.com"))
        // Do any additional setup after loading the view, typically from a nib.
    }


}

