#pragma once
#include <vector>
#include <memory>
#include "square.h"


using Squares = std::vector<std::unique_ptr<Square>>;

class Board
{
public:
    void appendSquare(std::unique_ptr<Square>);
    class iterator
    {
    public:
        iterator() {}
        iterator(Squares* board) : __board(board) {}
        iterator(const iterator& it) : __board(it.__board) {}
        iterator& operator++();
        iterator& operator--();
        iterator operator-();
        iterator operator+();
        Square* operator->();
        Square& operator*();

    private:
        Squares* __board = nullptr;
        unsigned currentElement = 0;
    };

    Board::iterator begin();


private:
    Squares board;
};

