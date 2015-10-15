//
//  Game.h
//  Project1
//
//  Created by Yunong Jiang on 1/10/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#ifndef Project1_Game_h
#define Project1_Game_h

class Pit;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nSnakes);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Pit* m_pit;
};

#endif
