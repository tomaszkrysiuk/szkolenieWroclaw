#pragma once
#include "square.h"

class BuyableSquare : public Square
{
public:
    void enter(Player& enteringPlayer);

private:
    virtual unsigned getFee() = 0;

    void chargeFee(Player& playerToCharge);
    void proposePurchase(Player& potentialBuyer);
    bool hasOwner();
};

