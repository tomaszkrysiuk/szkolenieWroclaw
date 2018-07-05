#pragma once
#include "square.h"

class Player;

class Start : public Square
{
public:
    void onPass(Player &passingPlayer) override;
    void onLeave(Player &leavingPlayer) override;
};

