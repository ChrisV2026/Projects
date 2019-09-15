//
//  ViewController.swift
//  Connect Four
//
//  Created by Christopher Vishnu on 2019-04-18.
//  Copyright © 2019 ChrisV. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var player = 1 //green
    var curr = 0 //initial value
    var playing = true
    var board = [[0,0,0,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,0,0]]
    var score = [0,0,0,0]
    
    var allplayer = [UIImageView]()
    var labels = [UILabel]()
    var double = false
    var doublecount = 0
    //make it so that they can pick the color

    func uncloak(){
        if(playercount == 2){
            Player1_1v1.isHidden = false
            Player2_1v1.isHidden = false
            Player1_1v1.image = imageArray[page[0]]
            Player2_1v1.image = imageArray[page[1]]
            Player1_1v1score.isHidden = false
            Player2_1v1score.isHidden = false
            double1_1v1.isHidden = false
            double2_1v1.isHidden = false
        }
            
        else if(playercount == 3){
            Player_1v1v1.isHidden = false
            Player3.isHidden = false
            Player4.isHidden = false
            Player_1v1v1.image = imageArray[page[1]]
            Player3.image = imageArray[page[0]]
            Player4.image = imageArray[page[2]]
            Player2score.isHidden = false
            Player3score.isHidden = false
            Player4score.isHidden = false
            double_1v1v1.isHidden = false
            double3.isHidden = false
            double4.isHidden = false
        }
            
        else if(playercount == 4){
            Player1.isHidden = false
            Player2.isHidden = false
            Player3.isHidden = false
            Player4.isHidden = false
            Player1.image = imageArray[page[0]]
            Player2.image = imageArray[page[1]]
            Player3.image = imageArray[page[2]]
            Player4.image = imageArray[page[3]]
            Player1score.isHidden = false
            Player2score.isHidden = false
            Player3score.isHidden = false
            Player4score.isHidden = false
            double1.isHidden = false
            double2.isHidden = false
            double3.isHidden = false
            double4.isHidden = false
        }
    }
    
    func cloak(){
        Player1_1v1.isHidden = true
        Player2_1v1.isHidden = true
        Player_1v1v1.isHidden = true
        Player1.isHidden = true
        Player2.isHidden = true
        Player3.isHidden = true
        Player4.isHidden = true
        Player1_1v1score.isHidden = true
        Player2_1v1score.isHidden = true
        Player1score.isHidden = true
        Player2score.isHidden = true
        Player3score.isHidden = true
        Player4score.isHidden = true
    }
    
    @IBAction func back(_ sender: Any) {
        let popup = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "PopUpVC") as! PopUpViewController
        self.addChild(popup)
        popup.view.frame = self.view.frame
        self.view.addSubview(popup.view)
        popup.didMove(toParent: self)
    }
    
    func changeturns(){
        player += 1
        if(player > playercount){
            player = 1
        }
        
        for i in 0..<allplayer.count{
            allplayer[i].removeShadow()
        }
        
        if(playercount == 2){
            allplayer[player+4].applyShadow()
        }
        
        else if(playercount == 3){
            if(player == 1){
                allplayer[2].applyShadow()
            }
            else if(player == 2){
                allplayer[4].applyShadow()
            }
            else if(player == 3){
                allplayer[3].applyShadow()
            }
        }
        
        else if(playercount == 4){
            allplayer[player-1].applyShadow()
        }
        
//        if(complayer[player-1]){
//            let s = ComOpp()
//            s.tag = 1
//            action(s)
//            comturn()
//            changeturns()
//        }
    }
    
    func startingscreen(){
        for i in 0..<allplayer.count{
            allplayer[i].removeShadow()
        }
        
        if(playercount == 2){
            allplayer[player+4].applyShadow()
        }
            
        else if(playercount == 3){
            allplayer[2].applyShadow()
        }
            
        else if(playercount == 4){
            allplayer[player-1].applyShadow()
        }
    }
    
    func showscore(){
        if(playercount == 2){
            labels[curr+3].text = String(score[curr - 1])
        }
            
        else if(playercount == 3){
            if(player == 1){
                labels[2].text = String(score[0])
            }
            else if(player == 2){
                labels[1].text = String(score[1])
            }
            else if(player == 3){
                labels[3].text = String(score[2])
            }
        }
            
        else if(playercount == 4){
            labels[curr-1].text = String(score[curr - 1])
        }
    }
    
    func checkValidDouble(index: Int, sender: AnyObject)->Bool{
        if(double && doublecount == 1){
            if(isWin(index: index)){
                board[index / 7][index % 7] = 0
                sender.setImage(nil, for: UIControl.State())
                return false
            }
            else{
                return true
            }
        }
        return true
    }
    
    func doublemove(sender: AnyObject){
        if(!double){
            
        }
        else if(checkValidDouble(index: sender.tag - 1, sender: sender) && doublecount == 1){
            double = false
            doublecount = 0
        }
        else if(checkValidDouble(index: sender.tag - 1, sender: sender) && doublecount == 0){
            doublecount = 1
        }
    }
    
    @IBAction func action(_ sender: AnyObject) {
        print(sender)
        
        if(board[(sender.tag - 1) / 7][(sender.tag - 1) % 7] == 0 && playing && playable(index: sender.tag - 1, type: type)){
            curr = player
            board[(sender.tag - 1) / 7][(sender.tag - 1) % 7] = player
            
            if(player == 1){
                sender.setImage(UIImage(named: "green circle.png"), for: UIControl.State())
                doublemove(sender: sender)
            }
            else if(player == 2){
                sender.setImage(UIImage(named: "red circle.png"), for:UIControl.State())
                doublemove(sender: sender)
            }
            
            else if(player == 3){
                sender.setImage(UIImage(named: "orange circle.png"), for:UIControl.State())
                doublemove(sender: sender)
            }
            
            else if(player == 4){
                sender.setImage(UIImage(named: "blue circle.png"), for:UIControl.State())
                doublemove(sender: sender)
            }
            
            //add a label for the winner and if it is a a draw
            let inwinState = isWin(index: sender.tag - 1)
            let indrawState = isDraw()
            
            if(inwinState){
                playAgainbutt.isHidden = false
                playing = false
                score[curr - 1] += 1
                showscore()
            }
            else if(indrawState){
                playAgainbutt.isHidden = false
                playing = false
            }
            else if(!double){
                changeturns()
            }
        }
    }
    
    func playable(index: Int, type: Bool) -> Bool{
        if(type){
            return gravitydown(index: index) || gravityup(index: index) || gravityleft(index: index) || gravityright(index: index)
        }
        else{
            return gravitydown(index: index)
        }
    }
    
    func gravityright(index: Int)->Bool{
        let x = index % 7
        
        if((6 - x) == 0){
            return true
        }
            
        else if((6 - x) > 0){
            if(board[index / 7][x + 1] != 0){
                return true
            }
        }
        return false
    }
    
    func gravityleft(index: Int)->Bool{
        let x = index % 7
        
        if(x == 0){
            return true
        }
            
        else if(x > 0){
            if(board[index / 7][x - 1] != 0){
                return true
            }
        }
        return false
    }
    
    func gravityup(index: Int)->Bool{
        let y = index / 7
        
        if(y == 0){
            return true
        }
            
        else if(y > 0){
            if(board[y - 1][index % 7] != 0){
                return true
            }
        }
        return false
    }
    
    func gravitydown(index: Int)->Bool{
        let y = index / 7
        
        if((6 - y) == 0){
            return true
        }
        
        else if((6 - y) > 0){
            if(board[y + 1][index % 7] != 0){
                return true
            }
        }
        return false
    }
    
    @IBOutlet weak var playAgainbutt: UIButton!    
    @IBAction func playAgain(_ sender: AnyObject) {
        board = [[0,0,0,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,0,0],
                 [0,0,0,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,0,0]]
        player = 1
        playing = true
        playAgainbutt.isHidden = true
        
        for i in 1...49{
            let button = view.viewWithTag(i) as! UIButton
            button.setImage(nil, for: UIControl.State.normal)
        }
        startingscreen()
        uncloak()
    }
    
    func isDraw() -> Bool{
        for i in 0...48{
            if(board[i / 7][i % 7] == 0){
                return false
            }
        }
        return true
    }
    
    func isWin(index: Int) -> Bool{
        for i in 0...3{
            
            //Vertical
            let pos1 = index / 7 - 3 + i
            let pos2 = index / 7 - 2 + i
            let pos3 = index / 7 - 1 + i
            let pos4 = index / 7 + i
            let offset = index % 7
            
            if(pos1 >= 0 && pos1 < 4){
                if(curr == board[pos1][offset] && curr == board[pos2][offset] && curr == board[pos3][offset] && curr == board[pos4][offset]){
                    return true
                }
            }

            //horizontal
            let off1 = index % 7 - 3 + i
            let off2 = index % 7 - 2 + i
            let off3 = index % 7 - 1 + i
            let off4 = index % 7 + i
            let pos = index / 7
            
            if(off1 >= 0 && off1 < 4){
                if(curr == board[pos][off1] && curr == board[pos][off2] && curr == board[pos][off3] && curr == board[pos][off4]){
                    return true
                }
            }
            
            //Diagonals
            let y1 = index / 7 - 3 + i
            let y2 = index / 7 - 2 + i
            let y3 = index / 7 - 1 + i
            let y4 = index / 7 + i
            let x1 = index % 7 - 3 + i
            let x2 = index % 7 - 2 + i
            let x3 = index % 7 - 1 + i
            let x4 = index % 7 + i
            let y4r = index / 7 - i
            let y3r = index / 7 + 1 - i
            let y2r = index / 7 + 2 - i
            let y1r = index / 7 + 3 - i
            if(y1 >= 0 && y1 < 4 && x1 >= 0 && x1 < 4){
                if(curr == board[y1][x1] && curr == board[y2][x2] && curr == board[y3][x3] && curr == board[y4][x4]){
                    return true
                }
            }
            if(y4r >= 0 && y4r < 4 && x1 >= 0 && x1 < 4){
                if(curr == board[y1r][x1] && curr == board[y2r][x2] && curr == board[y3r][x3] && curr == board[y4r][x4]){
                    return true
                }
            }
        }
        return false
    }
    
    @IBOutlet weak var Player1: UIImageView!
    @IBOutlet weak var Player2: UIImageView!
    @IBOutlet weak var Player3: UIImageView!
    @IBOutlet weak var Player4: UIImageView!
    @IBOutlet weak var Player2_1v1: UIImageView!
    @IBOutlet weak var Player1_1v1: UIImageView!
    @IBOutlet weak var Player_1v1v1: UIImageView!
    
    @IBOutlet weak var Player1score: UILabel!
    @IBOutlet weak var Player2score: UILabel!
    @IBOutlet weak var Player3score: UILabel!
    @IBOutlet weak var Player4score: UILabel!
    @IBOutlet weak var Player1_1v1score: UILabel!
    @IBOutlet weak var Player2_1v1score: UILabel!
    @IBOutlet weak var double1_1v1: UIButton!
    @IBOutlet weak var double2_1v1: UIButton!
    @IBOutlet weak var double1: UIButton!
    @IBOutlet weak var double2: UIButton!
    @IBOutlet weak var double3: UIButton!
    @IBOutlet weak var double4: UIButton!
    @IBOutlet weak var double_1v1v1: UIButton!
    
    
    
    @IBAction func doubleattck(_ sender: UIButton) {
        if(playercount == 3){
            if((player == 1 && sender.tag == 3) || (player == sender.tag) || (player == 3 && sender.tag == 4)){
                double = true
                sender.isHidden = true
            }
        }
        else{
            if(player == sender.tag){
                double = true
                sender.isHidden = true
            }
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        allplayer = [Player1, Player2, Player3, Player4, Player_1v1v1, Player1_1v1, Player2_1v1]
        labels = [Player1score, Player2score, Player3score, Player4score, Player1_1v1score, Player2_1v1score]
        cloak()
        uncloak()
        startingscreen()
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

}
