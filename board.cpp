#include "board.h"

void Board::appendSquare(std::unique_ptr<Square> newSquare)
{
    board.push_back(std::move(newSquare));
}

Board::iterator Board::begin()
{
    return iterator(&board);
}

Board::iterator& Board::iterator::operator++()
{
    if(not __board->empty())
        currentElement = (currentElement + 1) % __board->size();
    return *this;
}

Board::iterator& Board::iterator::operator--()
{
    if(not __board->empty())
        currentElement = (currentElement - 1 + __board->size()) % __board->size();
    return *this;
}

Square& Board::iterator::operator*()
{
    auto& board = *__board;
    return *(board[currentElement]);
}

Square* Board::iterator::operator->()
{
    auto& board = *__board;
    return board[currentElement].get();
}

