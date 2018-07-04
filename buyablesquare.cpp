#include "buyablesquare.h"


void BuyableSquare::enter(Player& enteringPlayer)
{
    if(hasOwner())
        chargeFee(enteringPlayer);
    else
        if(enteringPlayer.proposePurchase(this))
            owner = std::experimental::make_optional(&enteringPlayer);
}

void BuyableSquare::chargeFee(Player& playerToCharge)
{
    auto fee = getFee();
    if(owner)
        (*owner)->giveMoney(playerToCharge.takeMoney(fee));
}

bool BuyableSquare::hasOwner()
{
    return not owner;
}
