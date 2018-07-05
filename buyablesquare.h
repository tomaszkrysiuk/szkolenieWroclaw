#pragma once
#include <memory>
#include <experimental/optional>
#include "square.h"
#include "player.h"

class BuyableSquare : public Square
{
public:
    BuyableSquare(std::string name) : Square(name){}
    void onEnter(Player& enteringPlayer) override;

    virtual unsigned getPrice() = 0;
    void iOwnYou(Player& newOwner);
    void free();
private:
    virtual unsigned getFee() = 0;

    void chargeFee(Player& playerToCharge);
    void proposePurchase(Player& potentialBuyer);
    bool hasOwner();

    std::experimental::optional<Player*> owner;
};

