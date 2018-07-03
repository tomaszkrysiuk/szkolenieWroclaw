#pragma once
#include "square.h"

class Player;

class Start : public Square
{
public:
    void enter(Player& enteringPlayer) override;
    void pass(Player &passingPlayer) override;
    void leave(Player &leavingPlayer) override;
};

