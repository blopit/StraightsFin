//
//  Game.cpp
//  CS247_PROJ
//
//  Created by Shrenil Patel on 2015-06-18.
//  Copyright (c) 2015 ___SHRENILPATEL___. All rights reserved.
//

#include "Game.h"
#include <random>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    
    Game game = *new Game(atoi(argv[0]));
    
    game.round();
    
    return 0;
    
}


void Game::round(){
    shuffle();
    
    int j = 0;
    for (int p = 0; p < PLAYER_COUNT; p++) {
        for (int i = 0; i < 13; i++, j++) {
            Card card = *cards_[j];
            
            if (card.getRank() == SEVEN && card.getSuit() == SPADE) {
                turn = p;
            }
            
            players[p]->addCardToHand(card);
        }
    }
    
    cout << "A new round begins. It’s player " << (turn+1) << "’s turn to play." << endl;
    
    Command c;
    bool turnEnded = false;
    while (true) {
        
        if (players[turn]->isHuman()) {
            players[turn]->displayBoard();
        }
        
        c = (players[turn]->perform());

        
        switch (c.type) {
            case PLAY:{
                if (players[turn]->isLegalPlay(c.card.getSuit(), c.card.getRank())) {
                    
                    cout << "Player " << (turn+1) << " plays " << c.card << "." << endl;
                    
                    board.push_back(c.card);
                    players[turn]->removeCardFromHand(c.card);
                    
                    for (int i = 0; i < PLAYER_COUNT; i++) {
                        players[i]->updateBoard(c.card);
                    }
                    
                    turnEnded = true;
                }else{
                    cout << "This is not a legal play." << endl;
                }
                
                break;
            }
                
            case DISCARD:{
                if (!players[turn]->legalPlayExists()) {
                    cout << "Player " << (turn+1) << " discards " << c.card << "." << endl;
                    players[turn]->discard(c.card);
                    turnEnded = true;
                }else{
                    cout << "You have a legal play. You may not discard." << endl;
                }
                
                break;
            }
        
            case QUIT:{
                exit(0);
                break;
            }
        
            case DECK:{
                for (int i = 0; i < CARD_COUNT; i++) {
                    if (i == 0){
                        cout << *(cards_[i]);
                    }else if (i % 13 == 0){
                        cout << "\n" << *(cards_[i]);
                    }else{
                        cout << " " << *(cards_[i]);
                    }
                }
                break;
            }
                
            case RAGEQUIT:{
                players[turn] = new CompPlayer(*players[turn]);
                break;
            }
                
            default:
                break;
        };
        
        int handCount = 0;
        
        for (int i = 0; i < PLAYER_COUNT; i++) {
            handCount += players[i]->getHandSize();
        }
        
        if (handCount == 0) {
            
            bool game_over = false;
            for (int i = 0; i < PLAYER_COUNT; i++) {
                
                int gs = players[i]->getRoundScore() + players[i]->getGameScore();
                
                cout << "Player " << (i+1) << "’s discards:";
                players[i]->printDiscards();
                cout << "Player " << (i+1) << "’s score: " << players[i]->getGameScore() << " + ";
                cout << players[i]->getRoundScore() << " = " << (gs) << endl;
                
                players[i]->setGameScore(gs);
                
                if (gs >= 80){
                    game_over = true;
                }
            }
            
            
            if (game_over) {
                int min_score = players[0]->getGameScore();
                for (int i = 1; i < PLAYER_COUNT; i++) {
                    if (players[i]->getGameScore() < min_score) {
                        min_score = players[i]->getGameScore();
                    }
                }
                
                for (int i = 0; i < PLAYER_COUNT; i++) {
                    if (players[i]->getGameScore() == min_score) {
                        cout << "Player " << (i+1) << " wins!" << endl;
                    }
                }
                
                break;
                
            }else{
                for (int i = 0; i < PLAYER_COUNT; i++) {
                    players[i]->clearBoard();
                    players[i]->setRoundScore(0);
                    players[i]->clearDiscards();
                }
                round();
                break;
            }
        }
        
        if (turnEnded){
            turn++;
            turn = turn % PLAYER_COUNT;
            turnEnded = false;
        }
        
    }
    
}

void Game::shuffle(){
    static mt19937 rng(seed);
    
    int n = CARD_COUNT;
    
    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        Card *c = cards_[n];
        cards_[n] = cards_[k];
        cards_[k] = c;
    }
}

Game::Game(int s){
    seed = s;
    
    vector<Card> v;
    board = v;
    
    int i = 0;
    for (int suit = 0; suit < SUIT_COUNT; suit++) {
        for (int rank = 0; rank < RANK_COUNT; rank++, i++) {
            cards_[i] = new Card((Suit)suit, (Rank)rank);
        }
    }
    
    char player_type;
    for (i = 0; i < PLAYER_COUNT; i++) {
        cout << "Is player " << (i+1) << " a human(h) or a computer(c)?" << endl;
        
        cin >> player_type;
        
        if (player_type == 'h') {
            players[i] = new HumanPlayer();
        }else if (player_type == 'c') {
            players[i] = new CompPlayer();
        }
        
    }
    
}