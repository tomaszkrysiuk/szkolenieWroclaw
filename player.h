#pragma once

class Player
{
    Player(unsigned money);
    void giveMoney(unsigned amount);
    unsigned takeMoney(unsigned amount);
private:

    unsigned money;
};

