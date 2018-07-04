#pragma once
#include "buyablesquare.h"

class RailStation : public BuyableSquare
{
public:
    RailStation();
    unsigned getPrice() override;
    unsigned getFee() override;
};

