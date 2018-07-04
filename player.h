#pragma once
#include "board.h"

class BuyableSquare;

class Player
{
public:
    Player(unsigned money);
    void giveMoney(unsigned amount);
    unsigned takeMoney(unsigned amount);
    bool proposePurchase(BuyableSquare*);
    void move(unsigned);
    void setStartPoint(Board::iterator startPosition);
    Board::iterator& getCurrentPosition();

private:
    bool haveEnoughMoneyToPay(unsigned price);
    void buy(BuyableSquare* squareToBuy);
    void bankrupt();  // todo
    virtual bool wantsToBuy(BuyableSquare*) = 0;
    virtual void aboutToBankrupt() = 0;

    Board::iterator currentPosition;
    unsigned money;
    std::vector<BuyableSquare*> properties;
};

