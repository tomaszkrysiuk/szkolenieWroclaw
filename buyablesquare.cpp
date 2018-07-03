#include "buyablesquare.h"

BuyableSquare::BuyableSquare()
{

}


void BuyableSquare::enter(Player & enteringPlayer)
{
    if(hasOwner())
        chargeFee(enteringPlayer);
    else
        proposePurchase(enteringPlayer);
}

void BuyableSquare::chargeFee(Player& playerToCharge)
{
    auto fee = getFee();
    owner.giveMoney(playerToCharge.takeMoney(fee));
}

void BuyableSquare::proposePurchase(Player& potentialBuyer)
{
    //todo
}

bool BuyableSquare::hasOwner()
{

}
