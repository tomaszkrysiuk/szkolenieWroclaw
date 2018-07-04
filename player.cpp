#include "board.h"
#include "player.h"
#include "buyablesquare.h"
#include <iostream>
#include <algorithm>

Player::Player(unsigned money)
    : money(money)
{}

void Player::giveMoney(unsigned amount)
{
    money += amount;
}

unsigned Player::takeMoney(unsigned amount)
{
    if(money < amount)
        aboutToBankrupt();
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
    properties.push_back(squareToBuy);
    money -= squareToBuy->getPrice();
}

bool Player::haveEnoughMoneyToPay(unsigned price)
{
    return money >= price;
}

void Player::move(unsigned numberOfSteps)
{
    currentPosition->leave(*this);
    ++currentPosition;
    for(unsigned i=1; i<numberOfSteps; i++, ++currentPosition)
        currentPosition->pass(*this);
    currentPosition->enter(*this);
}

void Player::setStartPoint(Board::iterator startPosition)
{
    currentPosition = startPosition;
}
