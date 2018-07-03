#pragma once

class Player;

class Square
{
public:
    virtual void enter(Player&){}
    virtual void pass(Player&){}
    virtual void leave(Player&){}
};
