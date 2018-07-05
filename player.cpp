#include <iostream>
#include <algorithm>
#include "board.h"
#include "player.h"
#include "buyablesquare.h"
#include "bankruptcyobserver.h"

Player::Player(std::string name, unsigned money)
    : name(name), money(money)
{}

void Player::giveMoney(unsigned amount)
{
    money += amount;
}

unsigned Player::takeMoney(unsigned amount)
{
    if(money < amount)
        bankrupt();

    unsigned takenMoney = std::min(money, amount);
    money -= takenMoney;
    return takenMoney;
}

bool Player::proposePurchase(BuyableSquare* squareToBuy)
{
    if(not haveEnoughMoneyToPay(squareToBuy->getPrice()) or not wantsToBuy(squareToBuy))
        return false;
    buy(squareToBuy);
    return true;
}

void Player::buy(BuyableSquare* squareToBuy)
{
    payThePrice(squareToBuy->getPrice());
    aquireOwnership(squareToBuy);
    storeActOfOwnership(squareToBuy);
}

void Player::payThePrice(unsigned price)
{
    money -= price;
}

void Player::aquireOwnership(BuyableSquare* squareToBuy)
{
    squareToBuy->iOwnYou(*this);
}

void Player::storeActOfOwnership(ActOfOwnership actOfOwnership)
{
    properties.push_back(actOfOwnership);
}

void Player::bankrupt()
{
    freeProperties();
    bankruptcyObserver->notifyAboutBankruptcy();
}

void Player::freeProperties()
{
    for(auto property: properties)
        property->free();

    properties.clear();
}

bool Player::haveEnoughMoneyToPay(unsigned price)
{
    return money >= price;
}

void Player::move(unsigned numberOfSteps)
{
    leaveCurrentPosition();
    passOverIntermediateSquares(numberOfSteps);
    enterFinalPosition();
}

void Player::leaveCurrentPosition()
{
    position->onLeave(*this);
    ++position;
}

void Player::passOverIntermediateSquares(unsigned numberOfSteps)
{
    for(unsigned i=1; i<numberOfSteps; ++i, ++position)
        position->onPass(*this);
}

void Player::enterFinalPosition()
{
    position->onEnter(*this);
}

void Player::setStartPosition(Board::iterator startPosition)
{
    position = startPosition;
}

void Player::subscribeForBankruptcyNotification(BankruptcyObserver& observer)
{
    bankruptcyObserver = &observer;
}
