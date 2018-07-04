#pragma once
#include "player.h"

class BuyableSquare;

class Bot : public Player
{
public:
    using Player::Player;

private:
    bool wantsToBuy(BuyableSquare*) override;
};
