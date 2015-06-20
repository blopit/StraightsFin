//
//  Game.h
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#ifndef __CS247_PROJ__Game__
#define __CS247_PROJ__Game__

#include <stdio.h>
#include <vector>
#include "GenPlayer.h"

#include "HumanPlayer.h"
#include "CompPlayer.h"

#define PLAYER_COUNT 4

class Game{
    
public:
    void quit() const;
    Game(int);
    void shuffle();
    void round();
    
private:
    int turn;
    int seed;
    std::vector<Card> board;
    Card *cards_[CARD_COUNT];
    GenPlayer *players[PLAYER_COUNT];
    
};

#endif /* defined(__CS247_PROJ__Game__) */
