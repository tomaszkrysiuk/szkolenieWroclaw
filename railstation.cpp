#include "railstation.h"

RailStation::RailStation()
{

}

void RailStation::enter(Player &enteringPlayer)
{
    if(isOwned())
        takeMoney(enteringPlayer);
}

