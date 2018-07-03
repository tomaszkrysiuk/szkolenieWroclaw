#include "player.h"
#include <iostream>
#include <algorithm>

Player::Player(unsigned money) : money(money)
{
    std::cout << "Player::Player(unsigned money) : money(money)\n";
}

void Player::giveMoney(unsigned amount)
{
    money += amount;
}

unsigned Player::takeMoney(unsigned amount)
{
    unsigned takenMoney = std::min(money, amount);

    money -= takenMoney;
    return takenMoney;
}

