#include "game.h"
#include <iostream>

namespace
{
    struct GameOver{};
}

Game::Game(Board board, Players players) : board(std::move(board)), players(players)
{}

void Game::play()
{
    initializePlayers();

    try
    {
        while(true) playRound();
    }
    catch(const GameOver&)
    {
        std::cout << "Game is over\n";
    }

}

void Game::playRound()
{
    for(auto& player : players)
    {
        player->move(1);
        std::cout << " move()\n";
        if(isOver())
            throw GameOver();
    }
}

void Game::initializePlayers()
{
    for(auto& player : players)
    {
        player->setStartPosition(board.begin());
        player->subscribeForBankruptcyNotification(bankruptcyObserver);
    }
}

bool Game::isOver()
{
    return (players.size() - bankruptcyObserver.getBankruptciesCount()) < 2;
}
