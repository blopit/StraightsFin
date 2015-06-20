//
//  GenPlayer.h
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#ifndef __CS247_PROJ__GenPlayer__
#define __CS247_PROJ__GenPlayer__

#include <stdio.h>
#include "Card.h"
#include <vector>
#include <iostream>
#include "Command.h"

class GenPlayer{
public:
    
    GenPlayer(){};
    GenPlayer( const GenPlayer& );
    GenPlayer(std::vector<Card> table);
    void addCardToHand(Card);
    void removeCardFromHand(Card);
    void discard(Card);
    void printHand() const;
    
    virtual Command perform() = 0;
    bool isLegalPlay(Suit, Rank) const;
    bool legalPlayExists() const;
    
    void updateBoard(Card);
    void clearBoard();
    void clearDiscards();
    
    void printDiscards() const;
    int getRoundScore() const;
    int getGameScore() const;
    void setRoundScore(int);
    void setGameScore(int);
    int getHandSize() const;
    
    void displayBoard() const;
    virtual bool isHuman () = 0;
    
protected:
    std::vector<Card> board;
    std::vector<Card> hand;
    std::vector<Card> discardPile;
    
private:
    int roundScore;
    int gameScore;
    
};

#endif /* defined(__CS247_PROJ__GenPlayer__) */
