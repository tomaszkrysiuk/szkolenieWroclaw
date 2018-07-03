#pragma once
#include "square.h"

class RailStation : public Square
{
public:
    RailStation();
    void enter(Player& enteringPlayer);
};

