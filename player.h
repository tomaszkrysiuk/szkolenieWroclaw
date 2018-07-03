#pragma once

class Player
{
public:
    Player(unsigned money);
    void giveMoney(unsigned amount);
    unsigned takeMoney(unsigned amount);
private:

    unsigned money;
};

