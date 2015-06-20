//
//  GenPlayer.cpp
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#include "GenPlayer.h"

using namespace std;

void GenPlayer::addCardToHand(Card card){
    hand.push_back(card);
}

GenPlayer::GenPlayer( const GenPlayer& other){
    for (int i = 0; i < other.hand.size(); i++) {
        hand.push_back(other.hand[i]);
    }
    
    for (int i = 0; i < other.discardPile.size(); i++) {
        discardPile.push_back(other.discardPile[i]);
    }
    
    for (int i = 0; i < other.board.size(); i++) {
        board.push_back(other.board[i]);
    }
    
    roundScore = other.getRoundScore();
    gameScore = other.getGameScore();
}

void GenPlayer::printHand() const{
    for (int i = 0; i < hand.size(); i++) {
        cout << " " << hand[i];
    }
    cout << endl;
}

bool GenPlayer::isLegalPlay(Suit suit, Rank rank) const{
    
    if (board.size() == 0) {
        return (suit == SPADE && rank == SEVEN);
    }
    
    for (int i = 0 ; i < board.size(); i++) {
        
        if (rank == SEVEN)
            return true;
        
        if (board.at(i).getSuit() == suit && abs(board.at(i).getRank() - rank) == 1)
            return true;
        
    }
    
    return false;
}

bool GenPlayer::legalPlayExists() const{
    for (int i = 0; i < hand.size(); i++) {
        if (isLegalPlay(hand[i].getSuit(), hand[i].getRank())) {
            return true;
        }
    }
    return false;
}

void GenPlayer::updateBoard(Card c){
    board.push_back(c);
}

void GenPlayer::clearBoard(){
    board.clear();
}

void GenPlayer::removeCardFromHand(Card c){
    hand.erase(remove(hand.begin(), hand.end(), c), hand.end());
}

void GenPlayer::discard(Card c){
    
    roundScore += c.getRank() + 1;
    removeCardFromHand(c);
    discardPile.push_back(c);
    
}

void GenPlayer::printDiscards() const{
    for (int i = 0; i < discardPile.size(); i++) {
        cout << " " << discardPile[i];
    }
    cout << endl;
}

int GenPlayer::getRoundScore() const{
    return roundScore;
}

int GenPlayer::getGameScore() const{
    return gameScore;
}

void GenPlayer::setRoundScore(int newscore){
    roundScore = newscore;
}

void GenPlayer::setGameScore(int newscore){
    gameScore = newscore;
}

void GenPlayer::displayBoard() const{
    vector<Card> cardsSuits[4];
    
    int i = 0;
    for (int suit = 0; suit < SUIT_COUNT; suit++) {
        for (int rank = 0; rank < RANK_COUNT; rank++, i++) {
            for (int i = 0; i < board.size(); i++) {
                if (board.at(i).getRank() == rank && board.at(i).getSuit() == suit){
                    cardsSuits[(Suit)suit].push_back(board.at(i));
                }
            }
        }
    }
    
    cout << "Cards on the table:";
    cout << "\nClubs:";
    for (i = 0; i < cardsSuits[CLUB].size(); i++) {
        cout << " " << cardsSuits[CLUB].at(i);
    }
    cout << "\nDiamonds:";
    for (i = 0; i < cardsSuits[DIAMOND].size(); i++) {
        cout << " " << cardsSuits[DIAMOND].at(i);
    }
    cout << "\nHearts:";
    for (i = 0; i < cardsSuits[HEART].size(); i++) {
        cout << " " << cardsSuits[HEART].at(i);
    }
    cout << "\nSpades:";
    for (i = 0; i < cardsSuits[SPADE].size(); i++) {
        cout << " " << cardsSuits[SPADE].at(i);
    }
    cout << "\nYour hand:";
    printHand();
    
    cout << "Legal plays:";
    for (i = 0; i < hand.size(); i++) {
        if (isLegalPlay(hand.at(i).getSuit(), hand.at(i).getRank())) {
            cout << " " << hand.at(i);
        }
    }
    cout << endl;
}

int GenPlayer::getHandSize() const{
    return hand.size();
}

void GenPlayer::clearDiscards(){
    discardPile.clear();
}