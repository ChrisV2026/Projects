//
//  StartViewController.swift
//  Connect Four
//
//  Created by Christopher Vishnu on 2019-04-23.
//  Copyright © 2019 ChrisV. All rights reserved.
//

import UIKit

class StartViewController: UIViewController {
    
    var type = false
    var playercount = 0

    @IBAction func Regular(_ sender: Any) {
        type = false
        twoplayer.isHidden = false
        threeplayer.isHidden = false
        fourplayer.isHidden = false
        glow1.isHidden = false
    }
    
    @IBAction func Gravity4(_ sender: Any) {
        type = true
        twoplayer.isHidden = false
        threeplayer.isHidden = false
        fourplayer.isHidden = false
        glow2.isHidden = false
    }
    
    
    @IBAction func twoplayer(_ sender: Any) {
        //cloak()
        Player1_1v1.isHidden = false
        Player2_1v1.isHidden = false
        uncloak()
        playercount = 2
    }
    
    
    @IBAction func threeplayer(_ sender: Any) {
        //cloak()
        Player_1v1v1.isHidden = false
        Player3.isHidden = false
        Player4.isHidden = false
        uncloak()
        playercount = 3
    }
    
    
    @IBAction func fourplayer(_ sender: Any) {
        //cloak()
        Player1.isHidden = false
        Player2.isHidden = false
        Player3.isHidden = false
        Player4.isHidden = false
        uncloak()
        playercount = 4
    }
    
    
    func uncloak(){
        
    }
    
    @IBOutlet weak var Player1: UIImageView!
    @IBOutlet weak var Player2: UIImageView!
    @IBOutlet weak var Player3: UIImageView!
    @IBOutlet weak var Player4: UIImageView!
    @IBOutlet weak var Player2_1v1: UIImageView!
    @IBOutlet weak var Player1_1v1: UIImageView!
    @IBOutlet weak var Player_1v1v1: UIImageView!
    @IBOutlet weak var twoplayer: UIButton!
    @IBOutlet weak var threeplayer: UIButton!
    @IBOutlet weak var fourplayer: UIButton!
    @IBOutlet weak var glow1: UIImageView!
    @IBOutlet weak var glow2: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        twoplayer.isHidden = true
        threeplayer.isHidden = true
        fourplayer.isHidden = true
        glow1.isHidden = true
        glow2.isHidden = true

        // Do any additional setup after loading the view.
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
