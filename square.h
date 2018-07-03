#pragma once

class Player;

class Square
{
public:
    virtual void enter(Player&) = 0;
};
