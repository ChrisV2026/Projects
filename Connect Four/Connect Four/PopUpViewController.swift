//
//  PopUpViewController.swift
//  Connect Four
//
//  Created by Christopher Vishnu on 2019-04-23.
//  Copyright © 2019 ChrisV. All rights reserved.
//

import UIKit

class PopUpViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.black.withAlphaComponent(0.0)
        // Do any additional setup after loading the view.
    }
    

    @IBAction func cancel(_ sender: Any) {
        self.view.removeFromSuperview()
    }
    
    @IBAction func close(_ sender: Any) {
        performSegue(withIdentifier: "quit", sender: self)
        //self.view.removeFromSuperview()
    }
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
