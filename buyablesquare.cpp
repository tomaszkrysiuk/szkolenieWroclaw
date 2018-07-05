#include "buyablesquare.h"


void BuyableSquare::onEnter(Player& enteringPlayer)
{
    if(owner)
        chargeFee(enteringPlayer);
    else
        proposePurchase(enteringPlayer);
}

void BuyableSquare::chargeFee(Player& playerToCharge)
{
    auto fee = getFee();
    if(owner)
        (*owner)->giveMoney(playerToCharge.takeMoney(fee));
}

void BuyableSquare::proposePurchase(Player& enteringPlayer)
{
    if(enteringPlayer.proposePurchase(this))
        owner = std::experimental::make_optional(&enteringPlayer);
}

void BuyableSquare::iOwnYou(Player& newOwner)
{
    owner = &newOwner;
}

void BuyableSquare::free()
{
    owner = std::experimental::optional<Player*>();
}

