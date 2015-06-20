//
//  HumanPlayer.h
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#ifndef __CS247_PROJ__HumanPlayer__
#define __CS247_PROJ__HumanPlayer__

#include <stdio.h>
#include "GenPlayer.h"

class HumanPlayer: public GenPlayer{
public:
    HumanPlayer(){};
    Command perform() ;
    bool isHuman() {return true;}
};

#endif /* defined(__CS247_PROJ__HumanPlayer__) */
