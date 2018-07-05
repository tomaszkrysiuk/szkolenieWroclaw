#include "bot.h"
#include "buyablesquare.h"
#include <iostream>


bool Bot::wantsToBuy(BuyableSquare* square)
{
    std::cout << "Do You want to buy " << *square << " for " << square->getPrice() << "$ ?\n"
              << "You currently have " << money << "$\n(y/n): ";
    std::string answer;
    std::cin >> answer;
    return (answer == "y");
}
