#pragma once
#include <array>
#include <memory>


class Square;

template<unsigned N = 40>
class Game
{

private:

    using Board = std::array<std::unique_ptr<Square>, N>;

    Board board;
};

