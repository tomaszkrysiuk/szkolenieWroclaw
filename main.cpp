#include <iostream>
#include <memory>
#include "board.h"
#include "bot.h"
#include "railstation.h"
#include "game.h"
#include "start.h"


Board buildBoard();
Players createPlayers();

int main()
{
    Game game(buildBoard(), createPlayers());
    game.play();
    return 0;
}

Board buildBoard()
{
    Board board;
    board.appendSquare(std::make_unique<Start>());
    board.appendSquare(std::make_unique<RailStation>());

    return board;
}

Players createPlayers()
{
    return {std::make_shared<Bot>("Player1", 99),
            std::make_shared<Bot>("Player2", 99)};
}
