#pragma once

#include <vector>
#include "board.h"
#include "player.h"

using Players = std::vector<Player>;

class Game
{
    Game(Board board, Players players);

private:

    Board board;
    Players players;
};

