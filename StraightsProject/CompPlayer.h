//
//  CompPlayer.h
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#ifndef __CS247_PROJ__CompPlayer__
#define __CS247_PROJ__CompPlayer__

#include <stdio.h>
#include "GenPlayer.h"

class CompPlayer: public GenPlayer{
public:
    CompPlayer(){};
    CompPlayer( const GenPlayer& other): GenPlayer(other){};
    Command perform();
    bool isHuman() {return false;}
};

#endif /* defined(__CS247_PROJ__CompPlayer__) */
