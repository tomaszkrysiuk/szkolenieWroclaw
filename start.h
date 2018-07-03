#pragma once
#include "square.h"

class Start : public Square
{
public:
    Start();
    void enter(Player& enteringPlayer) override;
};

