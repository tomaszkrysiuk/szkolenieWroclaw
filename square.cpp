#include "square.h"

std::ostream& operator<<(std::ostream& os, const Square& s)
{
    return os << s.name;
}
