#pragma once

#include <vector>
#include "board.h"
#include "player.h"

using Players = std::vector<Player>;

class Game
{
public:
    Game(Board board, Players players);
    void play();


private:

    Board board;
    Players players;
};

