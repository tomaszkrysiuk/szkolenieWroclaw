#include "start.h"
#include "player.h"

void Start::onPass(Player &passingPlayer)
{
    passingPlayer.giveMoney(1);
}

void Start::onLeave(Player &leavingPlayer)
{
    leavingPlayer.giveMoney(1);
}



