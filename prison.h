#pragma once
#include "square.h"

class Prison : public Square
{
public:
    void enter(Player&) override;

};

#endif // PRISON_H
