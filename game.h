#pragma once

#include <vector>
#include "board.h"

using Players = std::vector<Player>;

class Game
{
    Game(Board board, Players players);

private:

    Board board;
    Players players;
};

