#pragma once
#include "buyablesquare.h"

class RailStation : public BuyableSquare
{
public:
    RailStation(std::string name) : BuyableSquare(name){}
    RailStation() : BuyableSquare("RailStation"){}
    unsigned getPrice() override;
    unsigned getFee() override;
};

