//
//  Subject.h
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-19.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#ifndef __CS247_PROJ__Subject__
#define __CS247_PROJ__Subject__

#include <stdio.h>
#include <vector>
#include "Card.h"

class Subject {
    
    std::vector < class Observer * > views;
public:
    Subject(){}
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void notify();
    std::vector<Card> getBoard() {
        return board;
    }
protected:
    std::vector<Card> board;
    
};


#endif /* defined(__CS247_PROJ__Subject__) */
