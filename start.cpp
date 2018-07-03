#include "start.h"

Start::Start()
{

}

void Start::pass(Player &enteringPlayer)
{
    enteringPlayer.giveMoney(400);
}

void Start::leave(Player &enteringPlayer)
{
    enteringPlayer.giveMoney(400);
}

