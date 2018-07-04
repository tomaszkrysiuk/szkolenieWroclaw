#pragma once
#include <memory>
#include <experimental/optional>
#include "square.h"
#include "player.h"

class BuyableSquare : public Square
{
public:
    void enter(Player& enteringPlayer) override;
    virtual unsigned getPrice() = 0;

private:
    virtual unsigned getFee() = 0;

    void chargeFee(Player& playerToCharge);
    void proposePurchase(Player& potentialBuyer);
    bool hasOwner();

    std::experimental::optional<Player*> owner;
};

