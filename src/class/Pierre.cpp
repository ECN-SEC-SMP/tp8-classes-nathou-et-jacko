#include "Pierre.hpp"

Pierre::Pierre(int x, int y) : Animal(x, y)
{
    this->name = NAME_PIERRE;
    this->living = 0;
}

Pierre::Pierre(int x, int y, int a, int b) : Animal(x, y, a, b)
{
    this->name = NAME_PIERRE;
    this->living = 0;
}


void Pierre::deplace(int maxX, int maxY)
{
    this->x = this->x;
    this->y = this->y;
}

void Pierre::setAttaque()
{
    this->typeAttaque = AttackType::ROCK;
}