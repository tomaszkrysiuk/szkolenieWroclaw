#include "game.h"

Game::Game(Board board, Players players) : board(std::move(board)), players(players)
{}

void Game::play()
{
    for(auto& player : players)
        player->setStartPoint(board.begin());
    while(players.size() > 1)
        for(auto& player : players)
            player->move(7);
}
