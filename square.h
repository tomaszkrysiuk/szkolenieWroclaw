#pragma once
#include <memory>


class Player;

class Square
{
public:
    Square() = default;
    Square(std::string name): name(name){}

    virtual void onEnter(Player&){}
    virtual void onPass(Player&){}
    virtual void onLeave(Player&){}
    virtual ~Square(){}

private:
    const std::string name = "NoName";
    friend std::ostream& operator<<(std::ostream&, const Square&);
};

std::ostream& operator<<(std::ostream& os, const Square& s);

