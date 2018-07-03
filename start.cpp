#include "start.h"
#include "player.h"

void Start::pass(Player &passingPlayer)
{
    passingPlayer.giveMoney(400);
}

void Start::leave(Player &leavingPlayer)
{
    leavingPlayer.giveMoney(400);
}

