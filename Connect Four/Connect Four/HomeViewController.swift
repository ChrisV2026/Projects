//
//  HomeViewController.swift
//  Connect Four
//
//  Created by Christopher Vishnu on 2019-04-23.
//  Copyright © 2019 ChrisV. All rights reserved.
//

import UIKit

var type = false
var playercount = 0
var page = [10,10,10,10]
var imageArray = [UIImage]()
var complayer = [false,false,false,false]

class HomeViewController: UIViewController {
    @IBOutlet weak var twoplayer: UIButton!
    @IBOutlet weak var threeplayer: UIButton!
    @IBOutlet weak var fourplayer: UIButton!
    @IBOutlet weak var Regular: UIButton!
    @IBOutlet weak var Gravity: UIButton!
    @IBOutlet weak var ScrollView1: UIScrollView!
    @IBOutlet weak var ScrollView2: UIScrollView!
    @IBOutlet weak var ScrollView3: UIScrollView!
    @IBOutlet weak var ScrollView4: UIScrollView!
    @IBOutlet weak var ScrollView5: UIScrollView!
    @IBOutlet weak var select1: UIButton!
    @IBOutlet weak var select2: UIButton!
    @IBOutlet weak var select3: UIButton!
    @IBOutlet weak var select4: UIButton!
    @IBOutlet weak var select5: UIButton!
    
    var count = 0
    
    @IBAction func Regular(_ sender: Any) {
        type = false
        twoplayer.isHidden = false
        threeplayer.isHidden = false
        fourplayer.isHidden = false
        Regular.layer.shadowOpacity = 1.0
        Gravity.layer.shadowOpacity = 0.0
        
    }
    
    @IBAction func Gravity4(_ sender: Any) {
        type = true
        twoplayer.isHidden = false
        threeplayer.isHidden = false
        fourplayer.isHidden = false
        Gravity.layer.shadowOpacity = 1.0
        Regular.layer.shadowOpacity = 0.0
    }
    
    @IBAction func twoplayer(_ sender: Any) {
        count = 0
        playercount = 2
        cloak(num: 2)
        twoplayer.layer.shadowOpacity = 1.0
        threeplayer.layer.shadowOpacity = 0.0
        fourplayer.layer.shadowOpacity = 0.0
    }
    
    
    @IBAction func threeplayer(_ sender: Any) {
        count = 0
        playercount = 3
        cloak(num: 3)
        twoplayer.layer.shadowOpacity = 0.0
        threeplayer.layer.shadowOpacity = 1.0
        fourplayer.layer.shadowOpacity = 0.0
    }
    
    
    @IBAction func fourplayer(_ sender: Any) {
        count = 0
        playercount = 4
        cloak(num: 4)
        twoplayer.layer.shadowOpacity = 0.0
        threeplayer.layer.shadowOpacity = 0.0
        fourplayer.layer.shadowOpacity = 1.0
    }
    
    @IBAction func select1(_ sender: Any) {
        page[0] = Int(ScrollView1.contentOffset.x / ScrollView1.frame.size.width)
        let ans = picked(index: 0)
        if(!ans){
            select1.isHidden = true
            changescreen(count: count)
        }
    }
    
    @IBAction func select2(_ sender: Any) {
        page[1] = Int(ScrollView2.contentOffset.x / ScrollView2.frame.size.width)
        let ans = picked(index: 1)
        if(!ans){
            select2.isHidden = true
            changescreen(count: count)
        }
    }
    
    @IBAction func select3(_ sender: Any) {
        page[2] = Int(ScrollView3.contentOffset.x / ScrollView3.frame.size.width)
        let ans = picked(index: 2)
        if(!ans){
            select3.isHidden = true
            changescreen(count: count)
        }
    }
    
    @IBAction func select4(_ sender: Any) {
        page[2] = Int(ScrollView4.contentOffset.x / ScrollView4.frame.size.width)
        let ans = picked(index: 2)
        if(!ans){
            select4.isHidden = true
            changescreen(count: count)
        }
    }
    
    @IBAction func select5(_ sender: Any) {
        page[3] = Int(ScrollView5.contentOffset.x / ScrollView5.frame.size.width)
        let ans = picked(index: 3)
        if(!ans){
            select5.isHidden = true
            changescreen(count: count)
        }
    }
    
    func picked(index: Int)->Bool{
        for i in 0..<page.count{
            if(index != i){
                if(page[i] == page[index]){
                    page[index] = 10
                    return true
                }
            }
        }
        count += 1
        return false
    }
    
    func changescreen(count: Int){
        if(count == playercount){
            performSegue(withIdentifier: "change", sender: self)
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        Regular.applyShadow()
        Gravity.applyShadow()
        twoplayer.applyShadow()
        threeplayer.applyShadow()
        fourplayer.applyShadow()
        // Do any additional setup after loading the view.
        imagescroll()
    }
    
    
    func cloak(num: Int){
        ScrollView3.isHidden = true
        ScrollView4.isHidden = true
        ScrollView5.isHidden = true
        
        select3.isHidden = true
        select4.isHidden = true
        select5.isHidden = true
        
        select1.isHidden = false
        select2.isHidden = false
        ScrollView1.isHidden = false
        ScrollView2.isHidden = false
        
        if(num == 3){
            ScrollView3.isHidden = false
            select3.isHidden = false
        }
            
        else if(num == 4){
            ScrollView4.isHidden = false
            ScrollView5.isHidden = false
            select4.isHidden = false
            select5.isHidden = false
        }
    }
    
    func imagescroll(){
        imageArray = [UIImage(named: "Selesnya.png"), UIImage(named: "atarka.png"), UIImage(named: "izzet.png"), UIImage(named: "simic.png"), UIImage(named: "dot.png")] as! [UIImage]
        
        
        for i in 0..<imageArray.count{
            let imageView = UIImageView()
            imageView.image = imageArray[i]
            imageView.contentMode = .scaleAspectFit
            let xpos = ScrollView1.frame.width * CGFloat(i)
            imageView.frame = CGRect(x: xpos, y: 0, width: ScrollView1.frame.width
                , height: ScrollView1.frame.height)
            ScrollView1.contentSize.width = ScrollView1.frame.width * CGFloat(i+1)
            ScrollView1.addSubview(imageView)

            let imageView2 = UIImageView()
            imageView2.image = imageArray[i]
            imageView2.contentMode = .scaleAspectFit
            let xpos2 = ScrollView2.frame.width * CGFloat(i)
            imageView2.frame = CGRect(x: xpos2, y: 0, width: ScrollView2.frame.width, height: ScrollView2.frame.height)
            ScrollView2.contentSize.width = ScrollView2.frame.width * CGFloat(i+1)
            ScrollView2.addSubview(imageView2)
            
            let imageView3 = UIImageView()
            imageView3.image = imageArray[i]
            imageView3.contentMode = .scaleAspectFit
            let xpos3 = ScrollView3.frame.width * CGFloat(i)
            imageView3.frame = CGRect(x: xpos3, y: 0, width: ScrollView3.frame.width
                , height: ScrollView3.frame.height)
            ScrollView3.contentSize.width = ScrollView3.frame.width * CGFloat(i+1)
            ScrollView3.addSubview(imageView3)
            
            
            let imageView4 = UIImageView()
            imageView4.image = imageArray[i]
            imageView4.contentMode = .scaleAspectFit
            let xpos4 = ScrollView4.frame.width * CGFloat(i)
            imageView4.frame = CGRect(x: xpos4, y: 0, width: ScrollView4.frame.width
                , height: ScrollView4.frame.height)
            ScrollView4.contentSize.width = ScrollView4.frame.width * CGFloat(i+1)
            ScrollView4.addSubview(imageView4)
            
            let imageView5 = UIImageView()
            imageView5.image = imageArray[i]
            imageView5.contentMode = .scaleAspectFit
            let xpos5 = ScrollView5.frame.width * CGFloat(i)
            imageView5.frame = CGRect(x: xpos5, y: 0, width: ScrollView5.frame.width
                , height: ScrollView5.frame.height)
            ScrollView5.contentSize.width = ScrollView5.frame.width * CGFloat(i+1)
            ScrollView5.addSubview(imageView5)
        }
        
        ScrollView2.contentOffset = CGPoint(x: ScrollView2.frame.size.width * 1, y: 0)
        ScrollView3.contentOffset = CGPoint(x: ScrollView2.frame.size.width * 2, y: 0)
        ScrollView4.contentOffset = CGPoint(x: ScrollView2.frame.size.width * 2, y: 0)
        ScrollView5.contentOffset = CGPoint(x: ScrollView2.frame.size.width * 3, y: 0)
    }
}

extension UIButton{
    func applyShadow(){
        self.layer.shadowColor = UIColor.yellow.cgColor
        self.layer.shadowOffset = CGSize(width: 0, height: 0)
        self.layer.shadowRadius = 5.5
        self.layer.masksToBounds = false
        self.layer.cornerRadius = 4.0
        self.layer.shadowOpacity = 0.0
    }
}

extension UIImageView{
    func applyShadow(){
        self.layer.shadowColor = UIColor.yellow.cgColor
        self.layer.shadowOffset = CGSize(width: 0, height: 0)
        self.layer.shadowRadius = 5.5
        self.layer.masksToBounds = false
        self.layer.cornerRadius = 7.0
        self.layer.shadowOpacity = 1.0
    }

    func removeShadow(){
        self.layer.shadowOpacity = 0.0
    }
}
