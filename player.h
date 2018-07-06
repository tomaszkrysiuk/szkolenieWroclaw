#pragma once
#include "board.h"
#include <string>

class BuyableSquare;
class BankruptcyObserver;



class Player
{
public:
    Player(std::string name, unsigned money);
    void giveMoney(unsigned amount);
    unsigned takeMoney(unsigned amount);
    bool proposePurchase(BuyableSquare*);
    void move(unsigned);
    void setStartPosition(Board::iterator startPosition);
    Board::iterator& getPosition();
    void subscribeForBankruptcyNotification(BankruptcyObserver &observer);

protected:
    std::string name;
    unsigned money;
private:

    using ActOfOwnership = BuyableSquare*;

    bool haveEnoughMoneyToPay(unsigned price);
    void buy(BuyableSquare* squareToBuy);
    void bankrupt();
    virtual bool wantsToBuy(BuyableSquare*) = 0;
    void leaveCurrentPosition();
    void passOverIntermediateSquares(unsigned numberOfSteps);
    void enterFinalPosition();
    void payThePrice(unsigned price);
    void storeActOfOwnership(ActOfOwnership actOfOwnership);
    void aquireOwnership(BuyableSquare *squareToBuy);
    void freeProperties();

    Board::iterator position;
    std::vector<ActOfOwnership> properties;
    BankruptcyObserver* bankruptcyObserver = nullptr;
};

