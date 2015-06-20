//
//  CompPlayer.cpp
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#include "CompPlayer.h"

using namespace std;

Command CompPlayer::perform(){
    
    Command c;
    
    for (int i = 0; i < hand.size(); i++) {
        if (isLegalPlay(hand[i].getSuit(), hand[i].getRank())) {
            c.type = PLAY;
            c.card = hand[i];
            return c;
        }
    }
    
    c.type = DISCARD;
    c.card = hand[0];
    return c;
    
}
