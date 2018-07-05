#pragma once

#include <vector>
#include "board.h"
#include "player.h"
#include "bankruptcyobserver.h"

using Players = std::vector<std::shared_ptr<Player>>;


class Game
{
public:
    Game(Board board, Players players);
    void play();

private:
    void playRound();
    void initializePlayers();
    bool isOver();

    Board board;
    Players players;
    BankruptcyObserver bankruptcyObserver;
};

