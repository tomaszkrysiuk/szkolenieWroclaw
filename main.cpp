#include <iostream>
#include <memory>
#include "board.h"
#include "bot.h"
#include "railstation.h"
#include "game.h"



int main()
{
    Board board;
    board.appendSquare(std::make_unique<RailStation>());
    Game game(std::move(board), {std::make_shared<Bot>(100), std::make_shared<Bot>(100)});
    game.play();
    return 0;
}
