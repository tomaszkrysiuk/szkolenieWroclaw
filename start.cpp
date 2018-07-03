#include "start.h"

Start::Start()
{

}

void Start::enter(Player &enteringPlayer)
{
    enteringPlayer.giveMoney(400);
}

